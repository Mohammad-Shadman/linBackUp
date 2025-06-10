# Remove dates in format YYYY-MM-DD or YYYY/MM/DD
s/[0-9]\{4\}[-/][0-9]\{2\}[-/][0-9]\{2\}//g

# Remove extra spaces after date removal
s/  */ /g

# Convert process statuses to lowercase only if they appear at the end of a line
s/ [Ss][Tt][Aa][Rr][Tt][Ee][Dd] *$/ started/

s/ [Ss][Tt][Oo][Pp][Pp][Ee][Dd] *$/ stopped/

s/ [Ff][Aa][Ii][Ll][Ee][Dd] *$/ failed/

s/ [Rr][Uu][Nn][Nn][Ii][Nn][Gg] *$/ running/
