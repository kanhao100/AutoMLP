
void AF_classifier(int a0,int a1,int a2,int a3,int a4,int a5,int a6,int len,int& result)
{
#pragma HLS INTERFACE ap_ctrl_none port=return
//#pragma HLS INTERFACE s_axilite port=return bundle=sqrt
#pragma HLS INTERFACE s_axilite port = a0
#pragma HLS INTERFACE s_axilite port = a1
#pragma HLS INTERFACE s_axilite port = a2
#pragma HLS INTERFACE s_axilite port = a3
#pragma HLS INTERFACE s_axilite port = a4
#pragma HLS INTERFACE s_axilite port = a5
#pragma HLS INTERFACE s_axilite port = a6
#pragma HLS INTERFACE s_axilite port = result
#pragma HLS INTERFACE s_axilite port=len

//#pragma HLS INTERFACE s_axilite port = in
//#pragma HLS INTERFACE s_axilite port = out
	//*result = 2;
	result = 2;


	ap_f A[7];
	A[0]=(float)a0/4096;A[1]=(float)a1/4096;A[2]=(float)a2/4096;A[3]=(float)a3/4096;A[4]=(float)a4/4096;A[5]=(float)a5/4096;A[6]=(float)a6/4096;



	int int_para = 1;
	ap_f Hw[12][7] = {{0.16549089550971985,0.18360957503318787,-0.3313962519168854,-0.14861644804477692,0.3512190282344818,0.1020238995552063,0.29603251814842224},
{0.06233784556388855,-0.11982250213623047,0.007000476121902466,0.3447308838367462,-0.3658578097820282,0.35520413517951965,-0.2263803482055664},
{-0.0052536725997924805,-0.1520979106426239,0.3196333944797516,0.15093979239463806,-0.3480713963508606,0.10982963442802429,-0.030407637357711792},
{-0.3567613661289215,0.2426866590976715,-0.32507553696632385,0.004196286201477051,-0.17436443269252777,0.004257291555404663,-0.30025047063827515},
{-0.09894412755966187,-0.044531434774398804,-0.060873597860336304,0.3569961488246918,0.08968862891197205,-0.2311110943555832,-0.14436420798301697},
{-0.24810384213924408,0.09209030866622925,0.07733464241027832,0.18760940432548523,0.02341654896736145,-0.06038364768028259,-0.36583390831947327},
{-0.2961199879646301,0.3006313145160675,-0.2982504665851593,0.07851773500442505,0.2752136290073395,-0.24360747635364532,-0.04721835255622864},
{-0.19330589473247528,-0.03895506262779236,-0.007209956645965576,0.11205050349235535,0.007572382688522339,0.287920743227005,-0.3521403968334198},
{-0.1264679729938507,-0.15122799575328827,0.0878383219242096,-0.3684302568435669,-0.26845085620880127,0.1461610496044159,0.3612871468067169},
{-0.0383337140083313,-0.2672337293624878,0.09886834025382996,-0.3616253435611725,0.03655168414115906,-0.23981139063835144,0.36679741740226746},
{0.33708974719047546,-0.28528526425361633,0.12554743885993958,0.18374070525169373,-0.29586201906204224,-0.3211822509765625,0.23182347416877747},
{-0.1884465515613556,-0.13425682485103607,0.016371876001358032,-0.1099274754524231,0.21264871954917908,-0.14666008949279785,-0.13137251138687134}};


ap_f Hb[12] = {0.23208341002464294,-0.0957832932472229,0.10985380411148071,0.1798987090587616,0.17116644978523254,-0.1647636741399765,-0.12963660061359406,0.32186266779899597,0.10970214009284973,0.07500326633453369,-0.34398722648620605,0.2752690613269806};


ap_f Hw2[16][12] = {{-0.2535841763019562,0.244998037815094,-0.23822836577892303,0.14260652661323547,0.1408851146697998,-0.20031559467315674,-0.24254947900772095,0.2762030363082886,-0.1278669685125351,0.1954297423362732,0.2742573618888855,-0.21763980388641357},
{-0.08195488154888153,0.2766970992088318,-0.225917786359787,0.13409918546676636,-0.05288517475128174,-0.21726858615875244,0.14370974898338318,0.12202993035316467,0.1746453046798706,-0.0912398099899292,0.07470962405204773,0.017646700143814087},
{-0.07980489730834961,0.03447073698043823,-0.012420177459716797,0.2086629867553711,0.2754850387573242,-0.08708667755126953,-0.026674747467041016,0.2630321979522705,0.05412212014198303,-0.03490206599235535,0.055525124073028564,0.07306984066963196},
{-0.14512813091278076,0.043384402990341187,0.2763437032699585,-0.27828750014305115,-0.03750917315483093,0.03992116451263428,0.06293857097625732,-0.10755789279937744,0.03126451373100281,0.06686124205589294,0.20580175518989563,-0.04331003129482269},
{-0.07920946180820465,0.13836586475372314,-0.052452608942985535,-0.004087239503860474,0.11018341779708862,0.09641152620315552,0.26562654972076416,-0.17160144448280334,-0.272937536239624,0.18913429975509644,0.04044625163078308,-0.12407450377941132},
{-0.017468899488449097,-0.0399964302778244,-0.029175102710723877,-0.15966445207595825,0.21270889043807983,-0.1935250610113144,-0.2581929564476013,-0.009355485439300537,0.0822974145412445,0.09043389558792114,-0.19623702764511108,0.2043568193912506},
{0.1271170675754547,-0.16451460123062134,-0.28662142157554626,-0.11553405225276947,-0.2577396035194397,-0.2069331407546997,0.2694161534309387,0.02623501420021057,0.12613928318023682,-0.1732662320137024,-0.02030324935913086,-0.2063036859035492},
{-0.15937469899654388,0.2318735122680664,0.1853901743888855,0.07135391235351562,-0.2838304340839386,0.048595815896987915,0.0006965398788452148,0.1655699610710144,0.24410057067871094,0.05132576823234558,0.001155555248260498,-0.1600811928510666},
{-0.17218226194381714,-0.21860474348068237,0.10597646236419678,-0.2619287371635437,0.1884349286556244,0.16226798295974731,0.26001083850860596,0.09188905358314514,-0.10823149979114532,-0.06906984746456146,-0.22372432053089142,0.11817416548728943},
{0.1115407645702362,0.13984939455986023,-0.06165403127670288,0.2704673409461975,-0.22651299834251404,-0.2401554435491562,-0.2002839297056198,0.004926323890686035,0.03724890947341919,-0.12091393768787384,-0.2070918083190918,0.16126218438148499},
{-0.10148811340332031,0.21128275990486145,-0.09832288324832916,-0.18354108929634094,-0.2157323658466339,0.02933219075202942,0.14728906750679016,-0.17627575993537903,-0.2575133442878723,-0.2260454297065735,0.031870514154434204,-0.16077099740505219},
{-0.06482544541358948,-0.2664538025856018,-0.23913514614105225,0.20319601893424988,0.006190627813339233,-0.005178987979888916,-0.10309280455112457,0.20270255208015442,-0.050493672490119934,-0.2340921312570572,-0.21860438585281372,0.09489411115646362},
{0.0553705096244812,0.05208081007003784,0.2788204550743103,-0.272899866104126,-0.2532891035079956,0.07898807525634766,0.26018500328063965,0.28648823499679565,-0.17534944415092468,-0.04191367328166962,0.2275632619857788,-0.04545736312866211},
{0.20111554861068726,-0.039549753069877625,-0.09731301665306091,0.13384857773780823,0.11851269006729126,-0.22059127688407898,-0.03838688135147095,-0.02244165539741516,-0.21251735091209412,-0.0692908763885498,0.09014284610748291,-0.23296387493610382},
{-0.22188302874565125,-0.15528470277786255,0.10917207598686218,0.13701972365379333,-0.09328272938728333,-0.005983680486679077,-0.14757181704044342,-0.23896779119968414,-0.2669529318809509,0.18934980034828186,0.049936890602111816,0.012262493371963501},
{0.2868334650993347,-0.1796228289604187,-0.033187657594680786,0.15699446201324463,-0.1988857388496399,0.08995598554611206,-0.24739503860473633,-0.016814321279525757,0.21516215801239014,-0.1209547221660614,0.07441458106040955,-0.25302788615226746}};


ap_f Hb2[16] = {-0.1743350625038147,0.023593157529830933,0.00016009807586669922,-0.1225152313709259,0.029485255479812622,0.06433674693107605,0.05496606230735779,0.024370968341827393,-0.0033941566944122314,0.15710335969924927,0.2636669874191284,0.1922268271446228,0.2448548674583435,0.021757155656814575,0.11111417412757874,0.09603038430213928};


ap_f Hw3[12][16] = {{0.016337424516677856,-0.04643777012825012,-0.03593763709068298,-0.09375980496406555,-0.17236319184303284,0.016268104314804077,-0.2459234595298767,-0.17512604594230652,-0.08420851826667786,0.19777461886405945,-0.16564100980758667,-0.21480712294578552,0.03020501136779785,0.21751680970191956,0.031852513551712036,-0.23263177275657654},
{0.1028599739074707,0.15165933966636658,0.025819778442382812,-0.14301666617393494,0.07231271266937256,0.05475413799285889,-0.011476069688796997,0.1883338987827301,-0.18318185210227966,0.06431704759597778,-0.08667293190956116,-0.17272594571113586,-0.00143355131149292,0.031858861446380615,0.14568066596984863,0.2043481469154358},
{0.15039163827896118,0.15339133143424988,-0.1375657618045807,-0.2058461606502533,0.1760118007659912,-0.129257470369339,0.09954485297203064,0.03174832463264465,0.04702314734458923,-0.23982325196266174,-0.05501404404640198,0.08642417192459106,-0.17487600445747375,0.0071385204792022705,0.23564529418945312,0.14317584037780762},
{0.21988648176193237,-0.09988975524902344,0.22496473789215088,-0.18790489435195923,-0.17486047744750977,0.06478747725486755,0.15916797518730164,-0.013982981443405151,-0.07068049907684326,0.19637244939804077,-0.1418437361717224,-0.07409843802452087,-0.23675388097763062,-0.00914698839187622,-0.028269827365875244,-0.16568896174430847},
{-0.24650681018829346,0.07378122210502625,-0.07839155197143555,-0.21154800057411194,-0.24695631861686707,-0.020124077796936035,-0.20039835572242737,-0.2160482406616211,-0.16246297955513,-0.1306726336479187,0.22218507528305054,-0.20955058932304382,-0.022866517305374146,0.13820841908454895,-0.029101401567459106,-0.22186654806137085},
{0.06201750040054321,0.05992516875267029,-0.07565757632255554,0.13268381357192993,-0.028563231229782104,-0.24010571837425232,0.197291761636734,0.1518503725528717,-0.04105234146118164,-0.24947717785835266,0.07259747385978699,-0.18646839261054993,0.12530261278152466,-0.09633615612983704,0.22609180212020874,0.04500168561935425},
{0.0073351263999938965,-0.06284123659133911,0.20526853203773499,-0.22867527604103088,0.15131187438964844,0.1626158058643341,0.1607324481010437,0.08466240763664246,0.02689337730407715,0.22559943795204163,0.22814509272575378,-0.09626296162605286,-0.20931774377822876,0.15922459959983826,0.23560389876365662,-0.10690641403198242},
{0.1693698763847351,-0.1973215639591217,-0.04132917523384094,-0.1183227002620697,0.10130318999290466,0.014000475406646729,0.15312248468399048,-0.23883700370788574,-0.06746658682823181,-0.22823694348335266,-0.12516120076179504,0.05114135146141052,-0.08987146615982056,0.11007118225097656,0.050436824560165405,0.10245326161384583},
{-0.03599625825881958,0.004782557487487793,-0.14739066362380981,-0.19982078671455383,-0.03615236282348633,-0.02234545350074768,-0.15679454803466797,0.05445101857185364,-0.05416867136955261,-0.14524468779563904,0.0543479323387146,-0.09880027174949646,0.17024576663970947,-0.14897435903549194,0.0867825448513031,0.029732227325439453},
{0.16359949111938477,0.026323944330215454,-0.1205289363861084,-0.1374206244945526,-0.12521886825561523,-0.24017030000686646,0.17034819722175598,-0.09153792262077332,0.05147463083267212,-0.1769062876701355,-0.14257380366325378,-0.18168428540229797,0.12652996182441711,-0.11780399084091187,0.13982990384101868,-0.07398262619972229},
{-0.16497060656547546,-0.057457566261291504,-0.10584026575088501,-0.006219923496246338,0.17114588618278503,-0.1452409327030182,0.24987608194351196,0.24987569451332092,-0.021580487489700317,0.08858034014701843,-0.0370730459690094,-0.00819939374923706,0.21333307027816772,-0.028379380702972412,0.0756358802318573,0.06568902730941772},
{0.23741364479064941,-0.2043285071849823,0.17355209589004517,-0.2248431146144867,-0.13323798775672913,-0.20568206906318665,-0.1969957947731018,-0.19937652349472046,-0.0327531099319458,0.08434292674064636,-0.2231464385986328,0.2056463062763214,-0.15592113137245178,0.1652340292930603,0.09407716989517212,0.20543566346168518}};


ap_f Hb3[12] = {-0.19587162137031555,-0.027230441570281982,0.01040196418762207,0.03031173348426819,0.11130231618881226,-0.2073761522769928,-0.12394601106643677,-0.1656104028224945,0.0006714761257171631,0.1791965365409851,-0.107664555311203,0.1366095244884491};


ap_f Ow[2][12] = {{0.009074985980987549,0.24635392427444458,-0.11031071841716766,-0.14002443850040436,0.14519688487052917,0.17140114307403564,-0.07080152630805969,-0.09254127740859985,0.14281779527664185,0.25920313596725464,0.1425108015537262,-0.0784720629453659},
{-0.06331001222133636,0.25392627716064453,0.09812000393867493,-0.04686667025089264,0.03510093688964844,0.252236008644104,0.1336730420589447,0.26444804668426514,-0.1350502222776413,0.12336581945419312,-0.25109532475471497,-0.022025346755981445}};


ap_f Ob[2] = {-0.249172180891037,0.2366066575050354};





	ap_f B[12],C[16],D[12],E[8],F[2];

	for (int i = 0; i < 12; i++) {
		B[i] = 0;
		for (int j = 0; j < 7; j++) {
			B[i] = B[i] + A[j] * Hw[i][j];
		}
		B[i] = B[i]/int_para + Hb[i] ;
		if(B[i] < 0){B[i] = 0;}
	}

	for (int i = 0; i < 16; i++) {
		C[i] = 0;
		for (int j = 0; j < 12; j++) {
			C[i] = C[i] + B[j] * Hw2[i][j];
		}
		C[i] = C[i]/int_para + Hb2[i] ;
		if(C[i] < 0){C[i] = 0;}
	}

	for (int i = 0; i < 12; i++) {
		D[i] = 0;
		for (int j = 0; j < 16; j++) {
			D[i] = D[i] + C[j] * Hw3[i][j];
		}
		D[i] = D[i]/int_para + Hb3[i] ;
		if(D[i] < 0){D[i] = 0;}
	}


		for (int i = 0; i < 2; i++) {
			F[i] = 0;
			for (int j = 0; j < 12; j++) {
				F[i] = F[i] + D[j] * Ow[i][j];
			}
			F[i] = F[i]/int_para + Ob[i] ;
		}
		//
    //std::cout<<F[0]<<':'<<F[1]<<':'<<std::endl;
	//*result = 1;

	if (F[0] > F[1])
		{result = 0 ;}

	else
		{result = 1;}
	if (A[0] == A[2] == A[6]){
		result = 2;
	}
}
