///   ( Sorting Algorithms ): ///

 
  #include <bits/stdc++.h>

  using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl
//#define MOD 1073741824

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

// const int N = 1e5+ 5    ;
//const int mod = 1e9+7 ;
//const ll mod = 1000000007LL;


const int N = 1e5+ 5    ;
const int mod = 1e9+7 ;


   
 // ************************************************************************************************ // 



  // Bubble Sort: repeatedly swap adjacent elements if they are in wrong order

void bubble_sort(vector<int> &a) {

    for (int i = 0; i < a.size(); ++i) {               // iterate over all elements

        for (int j = 0; j < a.size()-1; ++j) {         // compare adjacent pairs

            if (a[j] > a[j+1])                         // if left element is bigger than right

                swap(a[j], a[j+1]);                    // swap them
        }
    }
}



  // ************************************************************************************************* //

 


// Selection Sort: repeatedly select the minimum element and place it at the beginning

void selection_sort(vector<int> &a) {

    int n = a.size();

    for (int i = 0; i < n; ++i) {                     // ith minimum element

        for (int j = i+1; j < n; ++j) {               // check rest of the array

            if (a[i] > a[j])                          // if current is bigger than found

                swap(a[i], a[j]);                     // swap to place minimum at position i
        }
    }
}



   // ************************************************************************************************* //



// Insertion Sort: build sorted array by inserting current element into correct position

void insertion_sort(vector<int> &a) {

    int n = a.size();

    for (int i = 0; i < n; ++i) {                     // for each element

        for (int j = i; j > 0; --j) {                 // shift it backward while smaller than previous

            if (a[j] < a[j-1])

                swap(a[j], a[j-1]);                   // swap to correct position
        }
    }
}




  //  ************************************************************************************************** //




// Count Sort using frequency array and fixed-size vector

void count_sort(vector<int> &a) {

    int n = a.size();

    vector<int> vec;

    int mx = *max_element(a.begin(), a.end());        // find maximum element

    vector<int> freq(1e6 + 5, 0);                     // frequency array

    for (int i = 0; i < n; ++i)

        freq[a[i]]++;                                 // count occurrences

    for (int i = 0; i <= mx; ++i) {                  // rebuild sorted array

        while (freq[i]--)

            vec.push_back(i);
    }

    a = vec;                                          // overwrite original array

}




  // *************************************************************************************************************** //




// Count Sort another approach (same complexity)

void count__sort(vector<int> &a) {

    int n = a.size();
    vector<int> freq(1e6 + 5, 0);                    // frequency array

    for (int i = 0; i < n; ++i)

        freq[a[i]]++;                                 // count occurrences

    int p = 0;

    for (int i = 0; i <= 1e6; ++i) {                // rebuild array using pointer

        for (int j = 0; j < freq[i]; ++j) {

            a[p] = i;
            p++;
        }
    }
}


  // **************************************************************************************************************** //


// Count Sort handling negative numbers by shifting

void count_sort_shifting(vector<int> &a) {

    int n = a.size();

    int minElement = *min_element(a.begin(), a.end());

    minElement = abs(minElement);                    // shift all elements to non-negative

    for (int i = 0; i < n; ++i)

        a[i] += minElement;                          // apply shift

    int maxElement = *max_element(a.begin(), a.end());

    vector<int> freq(maxElement+1, 0);               // frequency array

    for (int i = 0; i < n; ++i)

        freq[a[i]]++;

    vector<int> res;

    for (int i = 0; i <= maxElement; ++i) {

        while (freq[i]--)                            // rebuild original values

            res.push_back(i - minElement);

    }

    a = res;                                          // overwrite original array
}




 // ********************************************************************************************************* // 


// Count Sort using frequency map (handles negative & large values efficiently)

void count_sort_frequency_map(vector<int> &a) {

    vector<int> res;

    int n = a.size();
    map<int, int> fm;                                 // map for frequency

    for (int i = 0; i < n; ++i)

        fm[a[i]]++;                                   // count occurrences

    for (auto it : fm) {                              // iterate sorted by key

        while (it.second--)                           // push elements by frequency

            res.push_back(it.first);

    }

    a = res;                                          // overwrite original array

}




  // ********************************************************************************************************************************// 

   

// Counting sort used in Radix Sort for a particular digit

void CountSort(vector<int> &a, ll place) {

    int n = a.size();

    vector<int> freq[10];                             // buckets for each digit (0-9)

    for (int i = 0; i < n; ++i) {

        int digit = (a[i] / place) % 10;             // extract digit at 'place'

        freq[digit].push_back(a[i]);                 // push into corresponding bucket

    }

    vector<int> res;

    for (auto it : freq) {                            // flatten buckets

        for (auto itr : it)

            res.push_back(itr);

    }

    a = res;                                          // overwrite array

}


// Radix Sort: sort numbers by digits starting from least significant

void Radix_Sort(vector<int> &a) {

    int mx = *max_element(a.begin(), a.end());        // find maximum element

    for (ll place = 1; mx/place > 0; place *= 10) {  // iterate over digit places

        CountSort(a, place);                          // stable sort by current digit

    }
}



     // *************************************************************************************************************************** // 


// Merge function for Merge Sort

void merge(int l, int mid, int r, vector<int> &v) {

    vector<int> a, b;

    for (int i = l; i <= mid; ++i)

        a.push_back(v[i]);                            // left subarray

    for (int i = mid+1; i <= r; ++i)

        b.push_back(v[i]);                            // right subarray

    int p = l, pa = 0, pb = 0;

    while (pa < a.size() && pb < b.size()) {         // merge two sorted subarrays

        if (a[pa] < b[pb])

            v[p++] = a[pa++];

        else

            v[p++] = b[pb++];

            // ans += a.size() - pa;                 // inversion count (optional) : // “Merge Sort-based Inversion Counting”
                                                    // directly gives you the minimum number of swaps between adjacent elements required to sort the array.
    }

    while (pa < a.size())

        v[p++] = a[pa++];                             // copy remaining left elements

    while (pb < b.size())

        v[p++] = b[pb++];                             // copy remaining right elements

}


// Merge Sort: divide-and-conquer recursive sort

  void merge_sort( int l, int r, vector<int> &v ) {

    if (l >= r) return;                               // base case: at most one element

    int mid = (l + r)/2;   // transition :  divide into 2 sub arrays
   

    merge_sort(l, mid, v);                            // sort left half

    merge_sort(mid+1, r, v);                          // sort right half

       // array l-> mid sorted
       // array mid+1 -> r sorted 	

    merge(l, mid, r, v);                              // merge sorted halves

}



   // *******************************************************************************************************************************// 



// Quick Sort: recursive divide-and-conquer sort using a pivot

void quick_sort(vector<int> &v) {

    if (v.size() <= 1) return;                        // base case: single element

    int pivot = v[v.size()-1];   //choose pivot (last element) // or // v [0] ;  // or : //  v [v.size() / 2 ] // 

    vector<int> left, right, center;

    for (int i = 0; i < v.size(); ++i) {             // partition elements

        if (v[i] > pivot)

            right.push_back(v[i]);

        else if (v[i] < pivot)

            left.push_back(v[i]);

        else
            center.push_back(v[i]);

    }

    quick_sort(left);                                 // recursively sort left

    quick_sort(right);                                // recursively sort right

    int p = 0;                                        // merge left + center + right

    for (int i = 0; i < left.size(); ++i)

        v[p++] = left[i];

    for (int i = 0; i < center.size(); ++i)

        v[p++] = center[i];

    for (int i = 0; i < right.size(); ++i)

        v[p++] = right[i];

}


// *********************************************************************************************************** // 





int main() {

    FastIO       //   input.txt   output.txt

   //  freopen("input.txt", "r", stdin);
     // freopen("output.txt", "w", stdout);

     int n ;
     cin >> n ;
    vector<int>vec(n) ;


    for (int i = 0; i < n; ++i) {


        cin >> vec[i] ;

    }

    count_sort(vec) ;



     return 0  ;

}

