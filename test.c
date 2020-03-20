int fuck = 3, shit, test = 4;
int fn(int n)
{
    int shit;
    shit = fuck - shit * test;
    return fn(shit+fuck);
}

int main()
{
    int fuck2;
    fuck2 = fn(fuck);
    fuck2 = shit - fuck * fuck / shit;
}
