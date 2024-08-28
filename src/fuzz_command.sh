target=${args[target]}
tool=${args[--tool]}
type=${args[--type]}
wordlist=${args[--wordlist]}
secure=${args[--secure]}
params=
url=
protocol=http

if [[ -z $target ]]; then
  if [[ -z $RHOST ]]; then
    echo -e "Invalid target/RHOST"
    exit 1
  fi

  target=$RHOST
fi

if [[ -z $tool ]]; then
  tool=ffuf
fi

if [[ -z $type ]]; then
  type=dns
fi

if [[ -z $wordlist ]]; then
  if [[ "$type" == "dns" ]]; then
    wordlist="-w \"/opt/fuzzdb/discovery/dns/dnsmapCommonSubdomains.txt\""
  fi

  if [[ "$type" == "dir" ]]; then
    wordlist="-w \"/opt/fuzzdb/discovery/predictable-filepaths/filename-dirname-bruteforce/raft-small-directories-lowercase.txt\""
  fi
fi

if [[ -n "$secure" ]]; then
  protocol=https
fi

if [[ "$type" == "dns" ]]; then
  params="-H \"Host: FUZZ.$target\""
  url="-u $protocol://$target"
fi

if [[ "$type" == "dir" ]]; then
  url="-u $protocol://$target/FUZZ"
fi

command="$tool -c -fs 0 $url $wordlist $params"

# print
echo -e "$(green Command:)" "$(yellow "$command")"

# execute
if [[ -z $DEBUG ]]; then
  eval $command
fi
