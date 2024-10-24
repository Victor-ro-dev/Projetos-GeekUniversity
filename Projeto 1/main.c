short missing_element (const short elements[100])
{
  int s=0;
  for(int i=0;i<100;i++)
    s+=elements[i];
  return 5050-s;
}
