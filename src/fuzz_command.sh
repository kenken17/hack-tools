target=${args[target]}
tool=${args[--tool]}
type=${args[--type]}
wordlist=${args[--wordlist]}
secure=${args[--secure]}

if [[ -z $target ]]; then
  if [[ -z $RHOST ]]; then
    echo -e "$(red Invalid target/RHOST)"
    exit 1
  fi

  target=$RHOST
fi

# default tool
checkAndSetIfEmpty tool "ffuf"

if [[ "$tool" == "ffuf" ]]; then
  if [[ ! $(command -v "$tool") ]]; then
    echo -e "$(red Missing "$tool")"
    exit 1
  fi
  # default action
  checkAndSetIfEmpty type "dns"

  if [[ -n $wordlist ]]; then
    wordlist="-w $wordlist"
  else
    wordlist=x

    checkAndSetIfEqual type "dns" "-w \"/opt/fuzzdb/discovery/dns/dnsmapCommonSubdomains.txt\"" wordlist

    checkAndSetIfEqual type "dir" "-w \"/opt/fuzzdb/discovery/predictable-filepaths/filename-dirname-bruteforce/raft-small-directories-lowercase.txt\"" wordlist
  fi

  # default http
  protocol=http
  checkAndSetIfExisted secure "https" protocol

  # default host
  params="-H \"Host: FUZZ.$target\""
  checkAndSetIfEqual type "dir" "" params

  # default just domain
  url="-u $protocol://$target"
  checkAndSetIfEqual type "dir" "-u $protocol://$target/FUZZ" url

  # form the command
  command="$tool -c $url $wordlist $params"

  # print
  echo -e "$(green Command:)" "$(yellow "$command")"
fi

# execute
if [[ -z $DEBUG ]]; then
  eval "$command"
fi
