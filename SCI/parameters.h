const int maxNp = 11;

const int N = 2;

const int Np[maxNp] = {12,12};

float values[N][maxNp + 1] = {
	-8.000000,-6.500000,-5.000000,-3.500000,-2.000000,-0.500000,0.500000,2.000000,3.500000,5.000000,6.500000,8.000000,
	-4.000000,-2.275000,-1.756250,-1.237500,-0.718750,-0.200000,0.300000,1.129750,1.959500,2.789250,3.619000,4.000000
};

const float m[N][maxNp] = {
	0.666667,0.666667,0.666667,0.666667,0.666667,1.000000,0.666667,0.666667,0.666667,0.666667,0.666667,0.579710,1.927711,1.927711,1.927711,1.927711,2.000000,1.205182,1.205182,1.205182,1.205182,2.624672
};

const float q[N][maxNp] = {
	5.333333,5.333333,5.333333,5.333333,5.333333,5.500000,5.666667,5.666667,5.666667,5.666667,5.666667,2.318841,5.385542,5.385542,5.385542,5.385542,5.400000,5.638445,5.638445,5.638445,5.638445,0.501312
};

const float data[] = {
	1.000000,
	1.000000,
	1.000000,
	1.000000,
	1.000000,
	0.998093,
	0.998613,
	0.999828,
	0.999984,
	0.183838,
	-0.999890,
	-0.996221,
	1.000000,
	1.000000,
	1.000000,
	0.998605,
	0.998802,
	0.998882,
	0.998999,
	0.999981,
	0.924077,
	-0.540654,
	-0.999984,
	-0.997867,
	1.000000,
	1.000000,
	0.998645,
	0.998928,
	0.999012,
	0.998856,
	0.999933,
	0.999988,
	0.175214,
	-0.999979,
	-0.999968,
	-0.997581,
	1.000000,
	0.998756,
	0.998935,
	0.998954,
	0.998870,
	0.998778,
	0.999989,
	0.802765,
	-0.807100,
	-0.999986,
	-0.999979,
	-0.999993,
	1.000000,
	0.999025,
	0.998986,
	0.998847,
	0.999869,
	0.999978,
	0.999965,
	-0.455311,
	-0.999990,
	-0.999933,
	-0.999996,
	-0.999997,
	0.999997,
	0.999988,
	0.998638,
	0.999321,
	0.999967,
	0.845869,
	-0.211158,
	-0.999989,
	-0.999975,
	-0.999979,
	-0.999996,
	-0.999988,
	0.999655,
	0.999988,
	0.999927,
	0.999980,
	0.971339,
	-0.229454,
	-0.999972,
	-0.999971,
	-0.998933,
	-0.999985,
	-0.999997,
	-0.798658,
	0.999997,
	0.999955,
	0.999975,
	0.703800,
	-0.504978,
	-0.999977,
	-0.999964,
	-0.999054,
	-0.999129,
	-0.998936,
	-1.000000,
	-1.000000,
	0.999994,
	0.999959,
	0.502932,
	-0.659277,
	-0.999978,
	-0.999953,
	-0.998960,
	-0.999179,
	-0.999078,
	-1.000000,
	-1.000000,
	-1.000000,
	0.999993,
	0.745112,
	-0.633543,
	-0.999964,
	-0.999931,
	-0.998748,
	-0.999095,
	-0.999168,
	-0.998896,
	-1.000000,
	-1.000000,
	-1.000000,
	0.999995,
	0.051802,
	-0.999980,
	-0.999927,
	-0.998870,
	-0.998979,
	-0.999090,
	-0.998833,
	-1.000000,
	-1.000000,
	-1.000000,
	-1.000000,
	0.999980,
	-0.495600,
	-0.999980,
	-0.997927,
	-0.998234,
	-0.998339,
	-0.998022,
	-1.000000,
	-1.000000,
	-1.000000,
	-1.000000,
	-1.000000
};