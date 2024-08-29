## after hook
##
## Any code here will be placed inside an `after_hook()` function and called
## after running any command.
##
## You can safely delete this file if you do not need it.

# print
echo -e "$(green Running command:)" "$(yellow "$command")"

# execute
if [[ -z $DEBUG ]]; then
  eval "$command"
fi

