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
	```  	
	**find()、find_if()、search()等函数的底层实现都采用的是顺序查找（逐个遍历）的方式，在某些场景中的执行效率并不高。例如，当指定区域内的数据处于有序状态时，如果想查找某个目标元素，更推荐使用二分查找的方法（相比顺序查找，二分查找的执行效率更高），lower_bound、upper_bound、equel_range、binary_search这 4 个查找函数，它们的底层实现采用的都是二分查找的方式**
	
25. all_of() 算法会返回 true，前提是序列中的所有元素都可以使谓词返回 true。  
	any_of() 算法会返回 true，前提是序列中的任意一个元素都可以使谓词返回 true。  
	none_of() 算法会返回 true，前提是序列中没有元素可以使谓词返回 true。  
	```cpp
	bool cmp(int n)	{return n > 10;}  
	vector<int> v = {1, 2, 3, 4, 4, 4, 4, 5, 9, 10, 21, 40, 60, 80};   
	bool isAll = all_of(v.begin(), v.end(), cmp);  
	cout << "所有元素都大于10：" << (isAll?"是":"否") << endl;  
	bool isAny = any_of(v.begin(), v.end(), cmp);  
	cout << "至少有一个元素大于10：" << (isAny?"是":"否") << endl;  
	bool isNone = none_of(v.begin(), v.end(), cmp);  
	cout << "没有元素大于10：" << (isNone?"是":"否") << endl;  
	```  
26. 如果两个序列的长度相同，并且对应元素都相等，equal() 算法会返回 true  
	```cpp
	vector<int> v1 = {1, 2, 3, 4, 4, 4, 4, 5, 9, 10, 21, 40, 60, 80};   
	vector<int> v2 = {1, 2, 3, 4, 4, 4, 4, 5, 9, 10, 21, 40, 60, 80};   
	bool ok = equal(v1.begin(), v1.end(), v2.begin(), v2.end());  
	cout << (ok?"v1 与 v2 内容完全相同" : "v1 与 v2 内容不相同") << endl;  
	```  
27. equal() 算法可以告诉我们两个序列是否匹配。mismatch() 算法也可以告诉我们两个序列是否匹配，而且如果不匹配，它还能告诉我们不匹配的位置。
	mismatch() 返回一个pair，pair 包含的迭代器指向第一对不匹配的元素。如果完全匹配，那么pair返回的就是两个序列的end位置
	```cpp
	vector<int> v1 = {1, 2, 3, 4, 4, 5, 5, 5, 9, 10, 21, 40, 60, 80};   
	vector<int> v2 = {1, 2, 3, 4, 4, 5, 5, 5, 9, 10, 21, 40, 60, 80, 90};   
	auto it = mismatch(v1.begin(), v1.end(), v2.begin(), v2.end());  
	if (it.first == v1.end() && it.second == v2.end()){  
		cout << "v1 与 v2 内容完全相同" << endl;  
	}  
	else {  
		cout << "v1 与 v2 内容的第一处差异出现在：" << endl;  
		cout << "v1 的第" << (it.first - v1.begin()) << "个字符处，内容为：" << *it.first << endl;   
		cout << "v2 的第" << (it.second - v2.begin()) << "个字符处，内容为：" << *it.second << endl;   
	}  
	```  
28. lexicographical_compare比较两个序列的字典序排列大小  
	如果第一个序列的字典序小于第二个，这个算法会返回 true，否则返回 false  
	```cpp  
	vector<int> v1 = {1, 2, 3, 4, 4, 4, 5, 5, 9, 10, 21, 40, 60, 80};     
	vector<int> v2 = {1, 2, 3, 4, 4, 5, 5, 5, 9, 10, 21, 40, 60, 80};   
	bool ret = lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());  
	cout << "比较结果：" << (ret?"true":"false") << endl;  
	
	vector<string> s1 = {"the", "cat", "is", "red"};  
	vector<string> s2 = {"the", "dog", "is", "yellow"};  
	ret = lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end());  
	cout << "比较结果：" << (ret?"true":"false") << endl;  
	```  
29. next_permutation() 会生成一个序列的重排列，它是所有可能的字典序中的下一个排列，默认使用 < 运算符来做这些事情。  
	它的参数为定义序列的迭代器和一个返回布尔值的函数，这个函数在下一个排列大于上一个排列时返回 true，如果上一个排列是序列中最大的，它返回 false，所以会生成字典序最小的排列。  
	```cpp
	vector<int> v = {2, 1, 3, 4};    
	do {   
		printVector(v); //一个自定义函数，打印vector的内容   
	}   
	while(next_permutation(v.begin(), v.end()));   
	```   
30. prev_permutation() 会生成一个序列的重排列，它是所有可能的字典序中的上一个排列，默认使用 < 运算符来做这些事情。  
	next_permutation() 是按照字典升序的方式生成的排列。当我们想以降序的方式生成排列时，可以使用 prev_permutation()。  
31. is_permutation() 算法可以用来检查一个序列是不是另一个序列的排列，如果是，会返回 true。  
	```cpp  
	vector<int> v1 = {2, 1, 3, 4};  
	vector<int> v2 = {4, 2, 3, 1};    
	bool ok = is_permutation(v1.begin(), v1.end(), v2.begin(), v2.end());  
	cout << "v2是v1的一个排列：" << (ok?"true":"false") << endl;  
	```  
32. copy_n() 算法可以从源容器复制指定个数的元素到目的容器中。  
	第一个参数是指向第一个源元素的输入迭代器，第二个参数是需要复制的元素的个数，第三个参数是指向目的容器的第一个位置的迭代器。  
	这个算法会返回一个指向最后一个被复制元素的后一个位置的迭代器  
	```cpp  
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};   
	vector<int> v2 = {55, 55, 55, 55};   
	copy_n(v2.begin(), v2.size(), v1.begin() + 3);  
	```  
33. copy() 算法可以将元素从源序列复制到目标序列。    
	前两个参数定义源序列的输入迭代器，第三个参数是指向目的序列的第一个位置的输出迭代器  
	函数会返回一个输出迭代器，它指向最后一个被复制元素的下一个位置。  
	```cpp  
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};   
	vector<int> v2 = {55, 66, 77, 88};   
	auto it = copy(v2.begin(), v2.end(), v1.begin() + 3);  
	```  
	copy_if() 算法可以从源序列复制使谓词返回 true 的元素，copy_if相当于在copy()的基础上，增加了一个过滤器，只有符合条件的元素才会被拷贝。  
	```cpp  
	bool cmp(int n){return n%2 == 0;}  
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};   
	vector<int> v2 = {55, 66, 77, 88};   
	copy_if(v2.begin(), v2.end(), v1.begin() + 3, cmp);  
	```  
34. 像 copy() 那样复制元素，但是从最后一个元素开始复制，最后复制第一个元素。  
	copy_backward() 会复制前两个迭代器参数指定的序列。第三个参数是目的序列的结束迭代器end（注意不是起始迭代器begin）  
	copy_backward()一般用于源地址和目的地址有重复，且元素向后复制的情况  
	```cpp
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};   
	auto it = copy_backward(v.begin(), v.begin() + 8, v.end());  
	```  
35. reverse_copy() 算法可以将源序列复制到目的序列中，目的序列中的元素是逆序的。定义源序列的前两个迭代器参数必须是双向迭代器。目的序列由第三个参数指定，它是目的序列的开始迭代器  
	这个算法会返回一个输出迭代器，它指向目的序列最后一个元素的下一个位置  
	如果是要对容器内容原地逆序，更好的选择是reverse()   
	```cpp  
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};   
	vector<int> v2(20);  
	auto it = reverse_copy(v.begin(), v.end(), v2.begin());  
	```  
36. unique() 算法可以在序列中原地移除重复的元素，这就要求被处理的序列必须是正向迭代器所指定的。  
	在移除重复元素后，它会返回一个正向迭代器作为新序列的结束迭代器。可以提供一个函数对象作为可选的第三个参数，这个参数会定义一个用来代替 == 比较元素的方法。  
	```cpp  
	vector<int> v = {1, 2, 3, 3, 5, 6, 6, 8, 9, 9, 0};   
	auto it = unique(v.begin(), v.end());  
	```  
37. rotate() 算法可以旋转容器中的元素序列  
	第一个参数是这个序列的开始迭代器；第二个参数是指向新的第一个元素的迭代器，它必定在序列之内。第三个参数是这个序列的结束迭代器。  
	元素的圆形序列会被维持，因此可以有效地旋转元素环，直到新的第一个元素成为序列的开始。这个算法会返回一个迭代器，它指向原始的第一个元素所在的新位置。  
	```cpp  
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};   
	auto it = rotate(v.begin(), v.begin() + 2, v.end());  
	v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};   
	it = rotate(v.begin(), v.end() - 2, v.end());  
	```  
38. rotate_copy() 算法会在新序列中生成一个序列的旋转副本，并保持原序列不变。rotate_copy() 的前 3 个参数和 copy() 是相同的；第 4 个参数是一个输出迭代器，它指向目的序列的第一个元素。  
	这个算法会返回一个目的序列的输出迭代器，它指向最后一个被复制元素的下一个位置。  
	```cpp  
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};   
	vector<int> v2(v.size());  //将旋转后的结果复制到这里  
	auto it = rotate_copy(v.begin(), v.begin() + 2, v.end(), v2.begin());  
	```  
39. move() 算法会将它的前两个输入迭代器参数指定的序列移到第三个参数定义的目的序列的开始位置，第三个参数必须是输出迭代器。  
	这个算法返回的迭代器指向最后一个被移动到目的序列的元素的下一个位置。  
	std::move算法（定义在 <algorithm>头文件中）的核心价值在于：  
	当处理支持移动语义的类型（如 std::string、std::vector或自定义包含资源的类）时，它可以通过转移资源所有权而非复制数据来显著提升性能。  
	对基本类型无效：int、double等简单类型没有动态资源，移动与拷贝开销相同，使用 std::move无性能收益。  
	```cpp  
	vector<string> vs = {"hello", "world", "you", "are", "good"};   
	vector<string> result(vs.size());    
	auto it = move(vs.begin(), vs.end(), result.begin());  
	```  
40. std::swap_ranges用于交换两个序列中指定范围内的元素。它需要三个迭代器参数：第一个序列的起止迭代器，以及第二个序列的起始迭代器。它会逐个交换对应位置上的元素，因此时间复杂度是线性的O(N)  
	当需要交换两个完整容器的所有内容时，优先使用 std::swap。特别是对于STL容器，它的效率极高（O(1)）  
	当只需要交换容器或数组中的一部分元素，或者需要在两个不同类别的容器（如 vector和 deque）之间交换元素时，使用 std::swap_ranges  
	```cpp  
	vector<int> v1 = {1, 2, 3, 4, 5};   
	vector<int> v2 = {100, 200, 300, 400, 500};   
	swap_ranges(v1.begin(), v1.begin() + 3, v2.begin());  
	```   
41. 如果不知道具体的场景，即元素保存在什么样的容器中，是不能从序列中移除元素的。  
	因此，“移除元素的”算法也无法做到这一点，它们只会重写被选择的元素或者忽略复制的元素。移除操作不会改变被“移除”元素的序列的元素个数。  
	有 4 种移除算法：  
	remove() 可以从它的前两个正向迭代器参数指定的序列中移除和第三个参数相等的对象。  
	基本上每个元素都是通过用它后面的元素覆盖它来实现移除的。它会返回一个指向新的最后一个元素之后的位置的迭代器。  
	remove_copy() 可以将前两个正向迭代器参数指定的序列中的元素复制到第三个参数指定的目的序列中，并忽略和第 4 个参数相等的元素。 它返回一个指向最后一个被复制到目的序列的元素的后一个位置的迭代器。序列不能是重叠的。  
	remove_if() 可以从前两个正向迭代器指定的序列中移除能够使作为第三个参数的谓词返回 true 的元素。   
	remove_copy_if() 可以将前两个正向迭代器参数指定的序列中，能够使作为第 4 个参数的谓词返回 true 的元素，复制到第三个参数指定的目的序列中。    
	它返回一个指向最后一个被复制到目的序列的元素的后一个位置的迭代器。序列不能是重叠的。  
	```cpp  
	cout << "========== remove ===========" << endl;  
	vector<int> v = {1, 2, 5, 4, 5, 5, 5, 8, 9, 10, 11, 12};   
	auto it = remove(v.begin(), v.end(), 5);  
	printVector(v); //自定义函数，打印vector的内容  
	cout << "返回的it位置(v)：" << it - v.begin() << endl;  
	
	cout << "========== remove_copy ===========" << endl;  
	v = {1, 2, 5, 4, 5, 5, 5, 8, 9, 10, 11, 12};   
	vector<int> v2(10);  
	it = remove_copy(v.begin(), v.end(), v2.begin(), 5);  
	printVector(v2); //自定义函数，打印vector的内容  
	cout << "返回的it位置(v2)：" << it - v2.begin() << endl;  
	
	cout << "========== remove_if ===========" << endl;  
	v = {1, 2, 5, 4, 5, 5, 5, 8, 9, 10, 11, 12};   
	it = remove_if(v.begin(), v.end(), cmp);  
	printVector(v); //自定义函数，打印vector的内容  
	cout << "返回的it位置(v)：" << it - v.begin() << endl;  
	
	cout << "========== remove_copy_if ===========" << endl;  
	v = {1, 2, 5, 4, 5, 5, 5, 8, 9, 10, 11, 12};   
	vector<int> v3(10);  
	it = remove_copy_if(v.begin(), v.end(), v3.begin(), cmp);  
	printVector(v3); //自定义函数，打印vector的内容  
	cout << "返回的it位置(v3)：" << it - v3.begin() << endl;  
	```  
42. fill() 和 fill_n() 算法提供了一种为元素序列填入给定值的简单方式  
	fill() 会填充整个序列； fill_n() 则以给定的迭代器为起始位置，为指定个数的元素设置值。  
	```cpp  
	vector<int> v(10);   
	fill(v.begin(), v.end(), 5);  
	vector<int> v2(10);  
	fill_n(v2.begin(), 6, 5);  
	```  
43. generate 与 generate_n这两个算法如同一个"数据工厂"，它们通过一个生成器函数来创造数据，并填充到指定的容器范围内  
	```cpp  
	int func (){  
		static int n = 0;  
		n = n+2;  
		return n;  
	}  
	vector<int> v(10);   
	generate(v.begin(), v.end(), func);  
	vector<int> v2(10);  
	generate_n(v2.begin(), 6, func);  
	```  
44. transform() 可以将函数应用到序列的元素上，并将这个函数返回的值保存到另一个序列中，它返回的迭代器指向输出序列所保存的最后一个元素的下一个位置。  
	```cpp  
	int func (int n){  
		return n*10;  
	}  
	string s = "Hello, World";   
	transform(s.begin(), s.end(), s.begin(), ::tolower);  
	  
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  
	transform(v.begin(), v.end(), v.begin(), func);  
	```  
45. replace() 算法会用新的值来替换和给定值相匹配的元素。它的前两个参数是被处理序列的正向迭代器，第 3 个参数是被替换的值，第 4 个参数是新的值。  
	replace_if() 会将使谓词返回 true 的元素替换为新的值。它的第 3 个参数是一个谓词，第 4 个参数是新的值。  
	replace_copy() 算法和 replace() 做的事是一样的，但它的结果会被保存到另一个序列中，而不会改变原始序列。它的前两个参数是输入序列的正向迭代器，第 3 个参数是输入序列的开始迭代器，最后两个参数分别是要被替换的值和替换值。  
	replace_copy_if() 和 replace_if() 算法是相同的，但它的结果会被保存到另一个序列中。它的前两个参数是输入序列的迭代器，第 3 个参数是输出序列的开始迭代器，最后两个参数分别是谓词和替换值  
	```cpp  
	cout << "================= replace =================" << endl;  
	vector<int> v = {1, 2, 5, 4, 5, 6, 7, 5, 9, 10};  
	replace(v.begin(), v.end(), 5, 500);  
	printVector(v); //自定义函数，打印vector的内容  
	  
	cout << "================= replace_if =================" << endl;  
	v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  
	replace_if(v.begin(), v.end(), cmp, 600);  
	printVector(v); //自定义函数，打印vector的内容  
	  
	cout << "================= replace_copy =================" << endl;  
	v = {1, 2, 5, 4, 5, 6, 7, 5, 9, 10};  
	vector<int> v2(10);  
	replace_copy(v.begin(), v.end(), v2.begin(), 5, 700);  
	printVector(v2); //自定义函数，打印vector的内容  
		  
	cout << "================= replace_if_copy =================" << endl;  
	v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  
	vector<int> v3(10);  
	replace_copy_if(v.begin(), v.end(), v3.begin(), cmp, 800);  
	printVector(v3); //自定义函数，打印vector的内容  
	```  