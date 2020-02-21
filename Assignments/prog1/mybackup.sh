# Validate input
if [ "$#" -gt "1" ]; then
    echo "USAGE: mybackup.sh [AGE]"
    exit
elif [ "$#" -eq "0" ]; then
    age=24
elif [[ ! $1 =~ ^[0-9]+$ ]]; then
    echo "USAGE: mybackup.sh [AGE]"
    echo "AGE is optional, but must be an integer"
    exit
else
    age=$1
fi

# Make sure backups directory exists
mkdir -p $HOME/Backups

# Create the archive
find $HOME -mmin -$(( age * 60 )) | tar -cf backup.$(date +%Y.%m.%d.%H.%M).tgz -T -