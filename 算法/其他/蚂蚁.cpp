void solve{
	int minT=0;
	for (int i=0;i<n;i++){
		int minT=0;
		for (i=0;i<n;i++){
			minT=max(minT,min(x[i],L-x[i]));
		}
		for (i=0;i<n;i++){
			maxT=max(maxT,max(x[i],L-x[i]));
		}
	}