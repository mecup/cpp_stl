# cpp_stl
**C++ STL示例代码**

01. sort() 排序  
	```cpp
	vector<string> vs = {"china", "usa", "japan", "germany", "france", "england", "india"};  
	sort(vs.begin(), vs.end());  
	vector<int> v = {56, 33, 98, 26, 43, 100, 12, 51, 6, 10, 88};  
	sort(v.begin(), v.end(), greater<int>());  
	```  
02. stable_sort() 排序（稳定），与sort的使用方法相同。  
03. partial_sort() 获取最大/小的指定数量的元素，例如100000个数字中最大的10个   
	partial_sort() 函数会以交换元素存储位置的方式实现部分排序的。具体来说，partial_sort() 会将范围内最小（或最大）的指定数量个元素移动到前面，并对这部分元素做升序（或降序）排序。例如将100000个数字的最大的10个移动到最前面的位置。  
	```cpp
	vector<int> v = {56, 33, 98, 26, 43, 100, 12, 51, 6, 10, 88};  
	partial_sort(v.begin(), v.begin()+3, v.end());  
	```  
	partial_sort_copy() 函数的功能和 partial_sort() 类似，唯一的区别在于，它不会对原有数据做任何变动，而是先将选定的部分元素拷贝到另外指定的数组或容器中，然后再对这部分元素进行排序。  
	```cpp
	vector<int> result(3);  
	partial_sort_copy(v.begin(), v.end(), result.begin(), result.begin()+3);
	```  
04. nth_element() 找到第几大/小的元素，例如100000个数字中第10大的元素  
	```cpp
	//nth_element函数会将你指定的第 nth个位置的元素放到它排序后应该在的位置，如果是第3小的数，那么会被放在[2]的位置上。  
	nth_element(v.begin(), v.begin()+2, v.end());  
	```  
05. is_sorted() 判断容器中的元素是否有序  
	is_sorted_until() 判断容器中的元素是否有序，返回一个迭代器：如果有序返回end()，如果无序返回指向第一个破坏有序性的元素的迭代器  
	```cpp
	vector<int> v = {56, 33, 98, 26, 43, 100, 12, 51, 6, 10, 88};
	bool ok = is_sorted(v.begin(), v.end());
	cout << "数组是否排序：" << (ok?"是":"否") << endl;
	```  
06. 如何选择排序函数？  
	当需要对普通数组或者 array、vector 或者 deque 容器中的元素进行排序时，怎样选择最合适（效率最高）的排序函数：  
	如果需要对所有元素进行排序，则选择 sort() 或者 stable_sort() 函数；  
	如果需要保持排序后各元素的相对位置不发生改变，就只能选择 stable_sort() 函数，而另外 3 个排序函数都无法保证这一点；  
	如果需要对最大（或最小）的 n 个元素进行排序，则优先选择 partial_sort() 函数；  
	如果只需要找到最大或最小的 n 个元素，但不要求对这 n 个元素进行排序，则优先选择 nth_element() 函数。  
	四个函数性能之间的比较：nth_element() > partial_sort() > sort() > stable_sort()       <--从左到右，性能由高到低  
08. merge() 将 2 个有序序列合并为 1 个有序序列，前提是这 2 个有序序列的排序规则相同（要么都是升序，要么都是降序）。得到的新有序序列的排序规则和这 2 个有序序列相同。  
	```cpp
	vector<int> result(100); //开辟一个足够大的vector，用来存储合并后的结果  
	int a1[] = {1, 7, 11, 15, 35};  
	int a2[] = {3, 8, 12, 28, 33, 39};  
 	auto resultEnd = merge(a1, a1+5, a2, a2+6, result.begin());
	```  
	inplace_merge() 当 2 个有序序列存储在同一个数组或容器中时，如果想将它们合并为 1 个有序序列，更推荐使用 inplace_merge() 函数  
	```cpp
	int a[] = {1, 7, 11, 15, 35, 3, 8, 12, 28, 33, 39};
	inplace_merge(a, a+5, a+11);
	```  
09. find() 用于在指定范围内查找和目标元素值相等的第一个元素，该函数会返回一个迭代器，当 find() 函数查找成功时，其指向的是查找到的第一个目标元素；如果查找失败，则该迭代器的指向end。
	```cpp
	vector<int> v = {1, 7, 11, 15, 35, 3, 8, 12, 28, 33, 39};
	auto it = find(v.begin(), v.end(), 15);
	```
10. 手动编写循环结构和调用 STL 算法函数相比，哪种实现方式更好呢？毫无疑问，直接调用算法会更好，理由有以下几个：  
	算法函数通常比自己写的循环结构效率更高；  
	自己写循环比使用算法函数更容易出错；  
	相比自己编写循环结构，直接调用算法函数的代码更加简洁明了。  
	使用算法函数编写的程序，可扩展性更强，更容易维护  
11. STL算法和容器中的成员方法同名时，该如何选择？  
	STL 标准库提供有 70 多种算法函数，其中有些函数名称和 STL 容器模板类中提供的成员方法名相同。  
	例如，STL 标准库提供了 sort() 和 merge() 函数（属于std::），而 list 容器模板类中也提供有同名的 sort() 和 merge() 成员方法。再比如，STL 标准库提供有 count()、find()、lower_bound()、upper_bound() 以及 equal_range() 这些函数，而每个关联式容器（除哈希容器外）也提供有相同名称的成员方法。  
	当某个 STL 容器提供有和算法同名的成员方法时，应该使用哪一个呢？大多数情况下，我们应该优先使用 STL 容器提供的成员方法，而不是同名的 STL 算法，原因包括：  
	虽然同名，但它们的底层实现并不完全相同。相比同名的算法，容器的成员方法和自身结合地更加紧密。  
	相比同名的算法，STL 容器提供的成员方法往往执行效率更高。  
12. find_if() 函数用于查找符合谓词函数规则的第一个元素，而 find_if_not() 函数则用于查找第一个不符合谓词函数规则的元素。  
	```cpp  
	auto it = find_if(v.begin(), v.end(), cmp);  
	```   
13. find_end() 在序列 A 中查找序列 B 最后一次出现的位置(也可以自定义规则) 函数会返回一个正向迭代器，当函数查找成功时，该迭代器指向A中查找到的第一个元素；反之，如果查找失败，则该迭代器的指向序列A的end()  
	```cpp  
	vector<int> A = {1, 2, 3, 4, 8, 12, 18, 1, 2, 3};  
	vector<int> B = { 1, 2, 3 };  
	auto it = find_end(A.begin(), A.end(), B.begin(), B.end());  
	```
14. find_first_of() 函数在 A 序列中查找和 B 序列中任意元素相匹配的第一个元素(也可以自定义规则)  
	```cpp
	vector<int> A = {1, 7, 11, 15, 35, 3, 8, 12, 28, 33, 39};  
	vector<int> B = {14, 15, 16};  
	auto it = find_first_of(A.begin(), A.end(), B.begin(), B.end());  
	```
15. adjacent_find() 函数用于在指定范围内查找 2 个连续相等的元素  
	```cpp
	auto it = adjacent_find(v.begin(), v.end());  .
	```
16. search() 函数的功能恰好和 find_end() 函数相反，用于在序列 A 中查找序列 B 第一次出现的位置  
17. 和 search() 一样，search_n() 函数也用于在指定区域内查找第一个符合要求的子序列。不同之处在于，前者查找的子序列中可包含多个不同的元素，而后者查找的只能是包含多个相同元素的子序列。  
	```cpp  
	auto it = search_n(v1.begin(), v1.end(), 3, 4); //在v1中查找连续3个4，返回第一个4的位置   
	auto it = search_n(v2.begin(), v2.end(), 3, 11, cmp); //查找3个连续的元素，它们每一个都能在cmp(该元素,11)执行时返回true  
	```  
18. partition 可直译为“分组”，partition() 函数可根据用户自定义的筛选规则，重新排列指定区域内存储的数据，使其分为 2 组，第一组为符合筛选条件的数据，另一组为不符合筛选条件的数据。  
	partition() 函数会返回一个迭代器，其指向的是两部分数据的分界位置，更确切地说，指向的是第二组数据中的第 1 个元素。  
	stable_partition() 函数可以保证对指定区域内数据完成分组的同时，不改变各组内元素的相对位置，用法与partition()相同。	 
	```cpp
	auto mid = partition(v1.begin(), v1.end(), cmp);
	```  
19. 在某些场景中，我们需要类似 partition() 或者 stable_partition() 函数“分组”的功能，但并不想对原序列做任何修改。这种情况下，就可以考虑使用 partition_copy() 函数。  
	partition_copy() 函数也能按照某个筛选规则对指定区域内的数据进行“分组”，并且分组后不会改变各个元素的相对位置。  
	更重要的是，partition_copy() 函数不会对原序列进行本地重新排列，而是以复制的方式将序列中各个数据“分组”到其它的指定位置存储。  
	partition_copy() 函数返回一个 pair 类型值，其包含 2 个迭代器，第一个迭代器指向的是第一个分组最后一个元素之后的位置；第二个迭代器指向的是第二个分组最后一个元素之后的位置	
	```cpp
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};    
	vector<int> oushu(10); //存储偶数   
	vector<int> jishu(10); //存储奇数  
	auto result = partition_copy(v.begin(), v.end(), oushu.begin(), jishu.begin(), cmp);  
	```  
20. partition_point() 函数可以在已分好组的数据中找到分界位置，该函数会返回一个正向迭代器，该迭代器指向的是 [first, last] 范围内第一个不符合 cmp 筛选规则的元素。
	```cpp
	vector<int> v = {1, 21, 3, 41, 5, 61, 7, 81, 9, 101, 2, 4, 6, 8}; 
	auto point = partition_point(v.begin(), v.end(), cmp);
	```  
	partition_point()与find_if_not()的差异：   
	(1)前提条件：最关键的区别     
	find_if_not() 对输入序列没有任何前提要求。它从 first开始逐个检查元素，直到找到第一个不满足谓词条件的元素。就像你在一份未分类的名单中，从头开始找第一个不是程序员的人。   
	partition_point() 则要求序列??已经是一个分区序列。这意味着序列中所有满足谓词条件的元素都必须排在所有不满足条件的元素之前。   
	它利用这个特性进行高效查找。好比一份名单已经按“是程序员”和“不是程序员”分成了前后两部分，partition_point()的任务是快速找到这两部分之间的那条分界线。  
	(2)性能：线性扫描 vs. 二分查找  
	由于 find_if_not()不知道序列的状态，它只能采用线性扫描，最坏情况下需要检查所有元素。  
	partition_point()知道序列是分区的，因此可以采用二分查找，效率高很多，尤其对于大型数据集。  
	(3)返回值：查找结果 vs. 分区边界  
	find_if_not() 返回的是第一个“不满足条件”的元素的迭代器。这直接是查找的结果。  
	partition_point() 返回的是“第二个分区”的起始迭代器。它指向的是第一个“不满足条件”的元素，但这个返回值还有一个含义是作为分区的标志点。你可以利用这个点将序列明确分成两个子范围。  
21. lower_bound() 函数用于在指定区域内查找不小于目标值的第一个元素，该函数仅适用于已排好序的序列，该函数返回指向下界位置的迭代器	
	```cpp
	vector<int> v = {1, 2, 3, 4, 4, 4, 4, 5, 9, 10, 9, 8, 7, 6};   
	auto bound = lower_bound(v.begin(), v.end(), 4);  
	cout << "元素4的下界位置：" << bound - v.begin();  
	```  
22. upper_bound() 函数用于在指定区域内查找大于目标值的第一个元素，该函数仅适用于已排好序的序列，该函数返回指向上界位置的迭代器  
	```cpp
	vector<int> v = {1, 2, 3, 4, 4, 4, 4, 5, 9, 10, 21, 40, 60, 80};   
	auto bound = upper_bound(v.begin(), v.end(), 4);  
	cout << "元素4的上界位置：" << bound - v.begin();   
	```  
23. equel_range() 函数的功能完全可以看做是 lower_bound() 和 upper_bound() 函数的合体，它返回一个pair，同时返回要查找元素在容器中的上界和下界位置的迭代器	
	```cpp
	vector<int> v = {1, 2, 3, 4, 4, 4, 4, 5, 9, 10, 21, 40, 60, 80}; 
	auto bound = equal_range(v.begin(), v.end(), 4);
	cout << "元素4的上界位置：" << bound.first - v.begin() << "，下界位置：" << bound.second - v.begin();
	```
24. binary_search() 函数，用于查找指定区域内是否包含某个目标元素，该函数会返回一个 bool 类型值
	```cpp
	int num = 6; //要查找的元素
	vector<int> v = {1, 2, 3, 4, 4, 4, 4, 5, 9, 10, 21, 40, 60, 80}; 
	bool isExist = binary_search(v.begin(), v.end(), num);
	cout << "是否存在" << num << "这个元素：" << (isExist?"是":"否") << endl;
	```  	**find()、find_if()、search()等函数的底层实现都采用的是顺序查找（逐个遍历）的方式，在某些场景中的执行效率并不高。例如，当指定区域内的数据处于有序状态时，如果想查找某个目标元素，更推荐使用二分查找的方法（相比顺序查找，二分查找的执行效率更高），lower_bound、upper_bound、equel_range、binary_search这 4 个查找函数，它们的底层实现采用的都是二分查找的方式**
	