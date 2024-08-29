## before hook
##
## Any code here will be placed inside a `before_hook()` function and called
## before running any command (but after processing its arguments).
##
## You can safely delete this file if you do not need it.
echo "==[ Before Hook Called ]=="
inspect_args

target=${args[target]}

if [[ -z $target ]]; then
  if [[ -z $RHOST ]]; then
    echo -e "$(red Invalid target/RHOST)"
    exit 1
  fi

  target=$RHOST
fi

