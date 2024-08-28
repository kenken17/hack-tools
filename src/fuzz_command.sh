target=${args[target]}
tool=${args[--tool]}
type=${args[--type]}

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
    wordlist=/opt/fuzzdb/discovery/dns/dnsmapCommonSubdomains.txt
  fi
fi

command="$tool -c -fs 0 -u http://$target -w $wordlist -H \"Host: FUZZ.$target\""

# print
echo -e "$(green Command:)" "$(yellow "$command")"

# execute
if [[ -z $DEBUG ]]; then
  $command
fi
