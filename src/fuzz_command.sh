tool=${args[--tool]}
flag=${args[--flag]}
type=${args[--type]}

# flags
wordlist=${args[--wordlist]}
secure=${args[--secure]}
size=${args[--size]}

# default tool
checkAndSetIfEmpty tool "ffuf"

if [[ "$tool" == "ffuf" ]]; then
  if [[ ! $(command -v "$tool") ]]; then
    echo -e "$(red Missing "$tool")"
    exit 1
  fi

  # default action
  checkAndSetIfEmpty type "dir"

  if [[ -n $wordlist ]]; then
    wordlist="-w $wordlist"
  else
    dnswordlist=$DNS_WORDLIST_MEDIUM
    checkAndSetIfEqual size "small" "$DNS_WORDLIST_SMALL" dnswordlist
    checkAndSetIfEqual size "medium" "$DNS_WORDLIST_MEDIUM" dnswordlist
    checkAndSetIfEqual size "large" "$DNS_WORDLIST_LARGE" dnswordlist

    filewordlist=$FILE_WORDLIST_MEDIUM
    checkAndSetIfEqual size "small" "$FILE_WORDLIST_SMALL" filewordlist
    checkAndSetIfEqual size "medium" "$FILE_WORDLIST_MEDIUM" filewordlist
    checkAndSetIfEqual size "large" "$FILE_WORDLIST_LARGE" filewordlist

    wordlist=x
    checkAndSetIfEqual type "dns" "-w \"$dnswordlist\"" wordlist

    checkAndSetIfEqual type "dir" "-w \"$dnswordlist\"" wordlist

    checkAndSetIfEqual type "file" "-w \"$filewordlist\"" wordlist
  fi

  # default http
  protocol=http
  checkAndSetIfExisted secure "https" protocol

  # default host
  params="-H \"Host: FUZZ.$target\""
  checkAndSetIfEqual type "dir" "" params
  checkAndSetIfEqual type "file" "" params

  # default just domain
  url="-u $protocol://$target"
  checkAndSetIfEqual type "dir" "-u $protocol://$target/FUZZ" url
  checkAndSetIfEqual type "file" "-u $protocol://$target/FUZZ" url

  # form the command
  command="$tool -c $url $wordlist $params $flag"
fi
