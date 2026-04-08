/**
           
                  Heap Sort using Max-Heap (Array-Based Implementation)  : 



     Description:

This algorithm sorts an array by first transforming it into a max-heap, a complete binary tree where every parent node is greater than its children.
After building the heap, the algorithm repeatedly swaps the maximum element (at index 0) with the last element in the heap and reduces the heap size.
Each removal is followed by a heapify (shift-down) operation to restore the max-heap property.

The process continues until all elements are extracted in descending order, achieving a full sort.    


  Main operations:

1. heapify(i)

Restores the max-heap property starting from index i by comparing the node with its left and right children, swapping with the larger one, and repeating recursively.

2. build()

Converts the entire array into a max-heap by calling heapify() on all non-leaf nodes from bottom to top.


3. HEAP_SORT()

Repeatedly:

- Prints the maximum element.

- Swaps it with the last element in the heap.

- Shrinks the heap size.

- Calls heapify(0) to restore the heap.




         ( Algorithm ) :
    **/

   
   

      int n  ;

         
         void heapify(int i) {   // Shift Down //

             int left = 2 * i + 1;

             int right = 2 * i + 2;

             int maxi = i;

             if (left < n and v[left] > v[maxi]) {

                 maxi = left;
             }

             if (right < n and v[right] > v[maxi]) {

                 maxi = right;
             }


             if (maxi != i) {

                 swap(v[i], v[maxi]);

                 heapify(maxi);
             }

         }




         void build() {

             for (int i = n / 2 - 1; i >= 0; --i) {

                 heapify(i);

             }

         }




         void HEAP_SORT () {

             for ( int i = n - 1; i >= 0; --i ) {


                 cout << v[0] << "\n";
                 swap(v[i], v[0]);

                 --n;

                 heapify(0);
             }


         }





          void PRINT ( ) {

             for (int i = 0; i < n ; ++i) {

                 cout << v[i] << "\n";
             }
             cout << el;

         }



     
int main() {


         ////   100 60 110 70 80 130 105   ////


    FastIO       //   input.txt   output.txt

    // freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);


    cin >> n ; 
     vector< int > v(n) ;

       for (auto &it : v ) {

            cin >> it ;
        }


     build ( ) ;

      heapsort( ) ;


      }

















       






  

        