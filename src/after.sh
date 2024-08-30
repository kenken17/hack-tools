## after hook
##
## Any code here will be placed inside an `after_hook()` function and called
## after running any command.
##
## You can safely delete this file if you do not need it.
debug=${args[--debug]}

# print
echo -e "$(green Running command:)" "$(yellow "$command")"

# execute
if [[ -z $DEBUG ]] && [[ -z $debug ]]; then
  eval "$command"
fi
