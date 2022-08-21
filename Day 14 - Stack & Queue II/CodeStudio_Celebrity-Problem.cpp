/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B);
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {

    int candidate = 0;
    for(int i = 1; i < n; i++)
    {
        if(knows(candidate, i))
            candidate = i;
    }

    for(int i = 0; i < n; i++)
    {
        if(i != candidate && knows(candidate, i) || i != candidate && !knows(i, candidate))
            return -1;
    }

    return candidate;
}
