#include <vector>
#include <algorithm>
#include "CppUnitTest.h"
#include "..\SortLib\BubbleSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortUnitTest
{
	TEST_CLASS(BubbleSortUnitTest)
	{
	public:
		template<typename Collection1, typename Collection2>
		void AreEqual(Collection1 const& col1, Collection2 const& col2)
		{
			Assert::AreEqual(col1.size(), col2.size());
			for (auto i1 = col1.begin(), i2 = col2.begin(); i1 != col1.end(); ++i1, ++i2)
				Assert::AreEqual(*i1, *i2);
		}

		template<typename Collection>
		void sortTest(Collection& toSort)
		{
			Collection sorted = toSort;
			std::sort(sorted.begin(), sorted.end());
			bubbleSort(toSort.begin(), toSort.end());
			AreEqual(sorted, toSort);
		}

		TEST_METHOD(SortEmpty)
		{
			std::vector<int> toSort = { };
			sortTest(toSort);
		}
		TEST_METHOD(Sort1)
		{
			std::vector<int> toSort = { 2 };
			sortTest(toSort);
		}
		TEST_METHOD(Sort2)
		{
			std::vector<int> toSort = { 12, 7 };
			sortTest(toSort);
		}
		TEST_METHOD(Sort2Sorted)
		{
			std::vector<int> toSort = { 23, 45 };
			sortTest(toSort);
		}
		TEST_METHOD(Sort5)
		{
			std::vector<int> toSort = { 15, 5, 10, 8, 3 };
			sortTest(toSort);
		}
		TEST_METHOD(Sort5Sorted)
		{
			std::vector<int> toSort = { 3, 5, 8, 10, 15 };
			sortTest(toSort);
		}
		TEST_METHOD(Sort10)
		{
			std::vector<int> toSort = { 51, 15, 55, 5, 22, 10, 34, 8, 3, 28 };
			sortTest(toSort);
		}
		TEST_METHOD(Sort10Sorted)
		{
			std::vector<int> toSort = { 3, 5, 8, 10, 15, 22, 28, 34, 51, 55 };
			sortTest(toSort);
		}
		TEST_METHOD(Sort10Duplicates)
		{
			std::vector<int> toSort = { 51, 55, 55, 5, 22, 3, 34, 8, 3, 28 };
			sortTest(toSort);
		}
		TEST_METHOD(Sort10SortedDuplicates)
		{
			std::vector<int> toSort = { 3, 5, 10, 10, 22, 28, 34, 51, 55, 55 };
			sortTest(toSort);
		}
		TEST_METHOD(Sort100)
		{
			std::vector<int> toSort = { 171, 6, 138, 781, 996, 909, 721, 511, 131, 347, 283, 361, 565, 840, 229, 918, 935, 760, 54, 990, 236, 459, 42, 280, 222, 294, 269, 757, 233, 572, 926, 553, 215, 590, 620, 412, 886, 595, 944, 153, 771, 550, 972, 765, 558, 124, 306, 256, 873, 786, 690, 250, 331, 525, 992, 303, 277, 71, 574, 866, 492, 746, 741, 166, 832, 720, 895, 1000, 878, 894, 265, 784, 830, 248, 530, 602, 83, 363, 891, 785, 95, 819, 916, 881, 228, 660, 68, 437, 205, 174, 912, 100, 674, 526, 823, 554, 274, 479, 85, 629 };
			sortTest(toSort);
		}
		TEST_METHOD(Sort1000)
		{
			std::vector<int> toSort = { 9564, 6176, 7489, 9960, 297, 9318, 7375, 5909, 3318, 1202, 9962, 3960, 8249, 1486, 185, 685, 5299, 323, 4284, 5214, 4669, 1229, 5007, 7385, 8488, 1218, 8771, 8897, 1572, 885, 455, 2619, 3931, 2463, 8894, 2305, 4420, 2507, 2588, 6906, 7386, 1149, 1665, 8652, 6316, 4576, 2960, 6012, 4805, 9153, 6656, 7563, 8386, 9761, 8243, 1480, 4741, 1432, 9051, 9495, 7362, 129, 4664, 8834, 6381, 6149, 58, 2241, 4377, 8660, 7843, 4682, 9280, 377, 9661, 9594, 7856, 4752, 4126, 7892, 2412, 6528, 4369, 99, 3427, 2283, 7851, 750, 2332, 72, 6041, 9880, 3571, 7697, 5113, 566, 6119, 9606, 1972, 2229, 7246, 805, 5833, 9515, 5295, 4824, 2892, 5042, 4110, 7061, 2772, 1667, 3723, 9949, 6450, 2987, 763, 1271, 4175, 8756, 6443, 5220, 3837, 7242, 2728, 226, 9168, 2610, 8079, 6208, 5281, 145, 4660, 4225, 2180, 9890, 2397, 7492, 1164, 7808, 8395, 7282, 7966, 6295, 5556, 9310, 2679, 358, 7768, 5458, 2954, 6126, 2451, 1795, 902, 8219, 7129, 8614, 5101, 5995, 3334, 8144, 7058, 2081, 1237, 1875, 3524, 639, 3008, 4782, 2695, 5649, 4092, 6779, 1055, 5316, 204, 6646, 5062, 4262, 9446, 9868, 4178, 3424, 1457, 9870, 9178, 7294, 2763, 5366, 3827, 4345, 4413, 8071, 7666, 8741, 244, 1412, 7540, 5401, 2842, 4002, 3143, 1386, 318, 2065, 9909, 3616, 8111, 7204, 7631, 2263, 4852, 7364, 7127, 675, 9427, 3356, 219, 2628, 900, 5454, 1029, 9317, 8720, 7406, 3586, 3585, 8477, 4779, 366, 3881, 3414, 3371, 4863, 8938, 3850, 4163, 1648, 2433, 4460, 8539, 9633, 1322, 6376, 9834, 4854, 3119, 4366, 497, 4268, 993, 8851, 9566, 3140, 637, 8327, 3122, 6880, 1296, 1100, 6040, 2069, 441, 4233, 8700, 6400, 6808, 5286, 360, 9447, 7208, 3859, 570, 7938, 3607, 3727, 7018, 9040, 8883, 2933, 6921, 4166, 4632, 5547, 8363, 5984, 4687, 101, 4562, 8294, 1581, 955, 5764, 4024, 9129, 3462, 2662, 1985, 8466, 5654, 694, 9719, 5962, 6891, 3476, 9588, 719, 2020, 8305, 9823, 3182, 3643, 1852, 701, 4972, 8529, 2725, 290, 8175, 7102, 5044, 2053, 8635, 9939, 6327, 347, 2648, 4807, 2972, 8995, 5015, 4668, 8374, 7509, 6788, 6196, 7194, 1442, 7113, 7098, 7444, 4919, 1615, 6357, 8457, 6028, 7740, 7560, 6270, 9528, 6536, 7409, 3913, 2860, 672, 1231, 1713, 3807, 7659, 6468, 6466, 1749, 6474, 9818, 4406, 4128, 7994, 5960, 613, 2751, 4689, 3169, 4096, 7332, 5452, 7840, 1803, 3954, 1246, 1332, 2992, 6469, 5970, 2812, 2254, 8104, 5334, 9155, 17, 2159, 1187, 1947, 3685, 9345, 7470, 7436, 9416, 5228, 9665, 6553, 585, 1036, 7867, 710, 9052, 8276, 7146, 4655, 240, 7435, 9103, 169, 5968, 2273, 1893, 2895, 2576, 1140, 970, 3400, 7327, 9121, 9024, 4769, 5511, 5690, 7110, 4905, 4085, 1892, 7118, 6143, 9729, 650, 7464, 6056, 312, 2745, 1092, 9162, 9634, 3457, 8749, 6812, 7165, 6724, 6918, 5681, 5608, 3133, 5709, 4738, 1760, 4482, 7534, 1477, 9875, 6384, 1890, 6221, 378, 8330, 260, 7038, 3927, 7835, 2989, 4492, 3704, 3943, 8333, 1939, 6420, 759, 2227, 8205, 6625, 3126, 196, 3746, 1059, 6121, 9605, 8543, 2568, 5433, 8236, 5187, 1485, 3219, 2438, 383, 9333, 7172, 4141, 1512, 855, 7418, 2961, 4713, 8069, 7644, 7099, 2859, 8575, 9423, 1637, 4487, 6051, 5952, 9213, 1043, 1013, 4028, 9891, 2564, 5147, 8343, 9134, 4003, 7672, 4568, 9475, 1966, 4195, 5879, 439, 1297, 5298, 6222, 623, 4744, 2494, 9734, 8159, 660, 1538, 7428, 6289, 4472, 659, 6288, 6982, 7395, 3707, 4219, 8130, 3049, 8435, 335, 6842, 4557, 3738, 3641, 1124, 4555, 1669, 6987, 9127, 5193, 8469, 2830, 3385, 371, 4756, 284, 1436, 4464, 6239, 3411, 5447, 6550, 8434, 2028, 643, 6723, 7121, 5973, 4657, 3344, 7945, 3928, 1061, 3448, 2414, 5528, 850, 1526, 5358, 688, 3757, 6696, 9762, 6515, 309, 2802, 9297, 7423, 9898, 6644, 9097, 5603, 4571, 1672, 540, 6387, 1068, 8682, 908, 2555, 7522, 48, 7639, 8527, 5445, 917, 4088, 8661, 7754, 9895, 9256, 2278, 8085, 8989, 1691, 6374, 7233, 9728, 2357, 2322, 4533, 1491, 3909, 475, 2035, 2529, 2783, 3492, 5223, 388, 1222, 7104, 7997, 4068, 5241, 9696, 968, 3866, 6087, 6512, 1171, 3177, 7044, 6309, 8451, 5522, 5934, 4976, 3671, 3015, 5503, 2917, 2586, 306, 3422, 8223, 6924, 8528, 8874, 487, 9918, 2257, 6769, 7079, 3941, 5133, 6741, 3744, 2084, 277, 8785, 8820, 6630, 9152, 8191, 8670, 3174, 761, 2473, 9536, 5570, 3632, 3663, 1300, 1018, 8402, 6963, 9491, 2008, 15, 4593, 8621, 1552, 7985, 4254, 8027, 3695, 4826, 6629, 9096, 4395, 1339, 8157, 2560, 4885, 6718, 546, 9984, 7964, 6975, 1242, 8248, 9382, 9291, 6377, 1991, 6949, 664, 1278, 5027, 7710, 549, 3549, 6933, 5291, 2800, 6520, 5416, 6269, 4457, 8259, 5318, 1792, 7978, 6977, 5609, 1655, 1239, 4308, 5355, 8431, 9926, 4033, 6956, 3759, 5368, 6733, 5740, 5122, 5640, 794, 9521, 1808, 8532, 5972, 5194, 8723, 9405, 8233, 5405, 3676, 2103, 3029, 5037, 222, 1916, 8941, 8148, 6874, 7134, 6753, 4277, 2819, 2708, 3819, 6903, 9598, 6686, 1730, 2510, 6151, 6068, 1403, 7874, 7095, 4261, 3972, 9591, 4466, 9164, 7483, 159, 2505, 4045, 8990, 6503, 7310, 5070, 5930, 9703, 2424, 7408, 2244, 8336, 2367, 4625, 1600, 3790, 2022, 1682, 881, 6393, 2873, 2778, 633, 6796, 4161, 7816, 2682, 5676, 8408, 7397, 4240, 592, 4462, 8636, 6580, 6071, 4149, 4087, 3920, 4331, 2614, 9878, 6837, 453, 6980, 3053, 7407, 5583, 8269, 5777, 6185, 6092, 7566, 3822, 2958, 2431, 4540, 3883, 1185, 9855, 298, 5421, 3517, 1562, 2524, 2072, 3152, 1394, 2496, 3168, 247, 5548, 6045, 1870, 521, 1856, 267, 8490, 6950, 8107, 7889, 947, 2669, 5585, 3844, 7971, 341, 3779, 6900, 8718, 7442, 4004, 7295, 3087, 1888, 2666, 7336, 162, 7106, 9111, 4300, 8560, 5237, 6786, 6394, 2272, 8768, 655, 2349, 103, 9160, 9173, 5481, 8313, 7510, 8676, 8550, 4172, 1333, 7834, 7277, 5486, 6263, 5159, 3193, 1688, 6296, 9929, 7400, 6284, 9512, 5819, 5997, 3531, 2672, 6983, 3626, 1144, 5338, 6734, 6836, 2021, 2378, 9190, 3658, 9210, 3231, 2962, 3289, 5615, 4389, 4239, 4860, 6370, 5495, 3025, 7549, 5580, 4479, 2310, 5030, 4057, 8118, 4119, 5365, 2183, 8633, 6694, 7673, 2781, 1293, 630, 3280, 1145, 5756, 1741, 6306, 4605, 3017, 8632, 7056, 9866, 7870, 1265, 6758, 578, 426, 5769, 2746, 9385, 5706, 5805, 4082, 9341, 2635, 8964, 3175 };
			sortTest(toSort);
		}
	};
}
