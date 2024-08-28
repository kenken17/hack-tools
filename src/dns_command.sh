target=${args[target]}
tool=${args[--tool]}
type=${args[--type]}

if [[ -z $tool ]]; then
  tool=dig
fi

if [[ -z $type ]]; then
  type=any
fi

command="$tool $target -t $type"

# print
echo -e "$(green Command:)" "$(yellow "$command")"

# execute
if [[ -z $DEBUG ]]; then
  eval $command
fi
