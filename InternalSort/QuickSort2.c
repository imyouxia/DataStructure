void swap(int *arr,int i,int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void qsort(int *arr,int left,int right)
{
    if(left >= right) 
        return;
    int index = left;
    for(int i = left + 1; i <= right; ++i)
    {
        if(arr[i] < arr[left])
        {
            swap(arr,++index,i);
        }
    }
    swap(arr,index,left);
    qsort(arr,left,index-1);
    qsort(arr,index+1,right);
}

