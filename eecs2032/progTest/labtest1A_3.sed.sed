# 1. Remove timestamps in the format [HH:MM:SS] anywhere in the line
s/\[[0-9]\{2\}:[0-9]\{2\}:[0-9]\{2\}\]//g

# 2. Replace multiple spaces with a single space
s/  */ /g

# 3. Convert log levels to uppercase only if they appear at the start of the line
s/[iI][nN][fF][oO] /INFO /g
s/[eE][rR][rR][oO][rR] /ERROR /g
s/[wW][aA][rR][nN] /WARN /g
