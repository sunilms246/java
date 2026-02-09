day=($day +%A)
if [ "$day" == "Saturday" ] || [ "$day" == "Sunday" ]; then
echo "this is weekend"
else
echo "this is weekday"
fi