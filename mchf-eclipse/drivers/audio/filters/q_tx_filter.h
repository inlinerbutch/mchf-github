/************************************************************************************
**                                                                                 **
**                               mcHF QRP Transceiver                              **
**                             K Atanassov - M0NKA 2014                            **
**                                                                                 **
**---------------------------------------------------------------------------------**
**                                                                                 **
**  File name:                                                                     **
**  Description:                                                                   **
**  Last Modified:                                                                 **
**  Licence:		CC BY-NC-SA 3.0                                                **
************************************************************************************/

#ifndef __Q_TX_FILTER_H
#define __Q_TX_FILTER_H

#define Q_TX_BLOCK_SIZE		1
#define Q_TX_NUM_TAPS			89


/*
 	 * Hilbert 0 Degree, "Phase-added" bandpass filter
     * Kaiser Window FIR Filter, Beta = 3.25, Raised Cosine = 9.30
     * Fc = 1.68 kHz
     * BW = 2.40 kHz
     * 89 Taps
     * -1dB @ 809, 2570 Hz
     * -3dB @ 562, 2790 Hz
     * -6dB @ 363, 3000 Hz
     *
     * 20140926 by KA7OEI using Iowa Hills Hilbert Filter Designer
*/
// 90.00 degrees
//

const float q_tx_coeffs[Q_NUM_TAPS] =
{
		 0.000350654345247197,
		 0.000048495992345331,
		-0.00030269367796739,
		-0.0006372882859413,
		-0.00087509973453087,
		-0.000935438190780461,
		-0.000754786181251458,
		-0.000305076447746045,
		 0.000391193062498882,
		 0.001252872752221318,
		 0.002142273501865866,
		 0.002879164026692220,
		 0.003266240907652578,
		 0.003123269326812048,
		 0.002324847939360293,
		 0.000835123181875766,
		-0.00126781478075111,
		-0.00378440540018013,
		-0.00640742646669138,
		-0.0087583497543795,
		-0.0104434793669819,
		-0.0111230548367379,
		-0.0105831083580657,
		-0.0087978405775875,
		-0.00597016098432496,
		-0.00254008056502865,
		 0.000845262048696830,
		 0.003400500117241970,
		 0.004304009856972469,
		 0.002820955170573835,
		-0.00156939450577235,
		-0.00906140059757262,
		-0.0194448000601471,
		-0.0320759567220048,
		-0.0459079022907017,
		-0.0595802803158307,
		-0.0715613640600165,
		-0.0803259842254938,
		-0.084546832254861,
		-0.0832733068707249,
		-0.0760725082534,
		-0.0631112465220493,
		-0.0451655026636182,
		-0.0235536028957205,
		-971.5105807436250E-18,
		 0.023553602895718607,
		 0.045165502663616526,
		 0.063111246522047970,
		 0.076072508253399146,
		 0.083273306870724484,
		 0.084546832254861107,
		 0.080325984225494251,
		 0.071561364060017327,
		 0.059580280315831659,
		 0.045907902290702789,
		 0.032075956722005861,
		 0.019444800060148069,
		 0.009061400597573368,
		 0.001569394505772855,
		-0.00282095517057357,
		-0.00430400985697243,
		-0.0034005001172421,
		-0.000845262048697074,
		 0.002540080565028352,
		 0.005970160984324673,
		 0.008797840577587255,
		 0.010583108358065545,
		 0.011123054836737856,
		 0.010443479366981914,
		 0.008758349754379589,
		 0.006407426466691522,
		 0.003784405400180281,
		 0.001267814780751256,
		-0.000835123181875646,
		-0.00232484793936021,
		-0.00312326932681201,
		-0.00326624090765258,
		-0.00287916402669225,
		-0.00214227350186591,
		-0.00125287275222137,
		-0.000391193062498925,
		 0.000305076447746017,
		 0.000754786181251448,
		 0.000935438190780470,
		 0.000875099734530894,
		 0.000637288285941334,
		 0.000302693677967427,
		-0.000048495992345297,
		-0.0003506543
};

//
// Same as above, but set to 89.50 degrees
//

const float q_tx_coeffs_minus[Q_NUM_TAPS] =
{
		 0.000338712017039131,
		 0.000035020356392600,
		-0.000316545004415885,
		-0.000650132273189021,
		-0.000885595444496015,
		-0.000942618895181534,
		-0.000758399358985275,
		-0.0003058603655592,
		 0.000391369760756401,
		 0.001251069175148371,
		 0.002134764963043565,
		 0.002861953042489475,
		 0.003235736388185435,
		 0.003077035189206267,
		 0.002262289393385770,
		 0.000757965890379345,
		-0.0013553846901003,
		-0.00387603214814716,
		-0.0064953333296456,
		-0.00883449229943655,
		-0.0105009662116058,
		-0.0111576270605984,
		-0.0105944234037114,
		-0.00879029964043812,
		-0.0059530569294151,
		-0.0025269254846095,
		 0.000838253137920751,
		 0.003356656152318832,
		 0.004208932704965734,
		 0.002665371523542286,
		-0.00178708271236726,
		-0.00933329605940138,
		-0.0197527861834173,
		-0.0323923096384613,
		-0.0461973038162893,
		-0.0598030973060455,
		-0.0716778645673315,
		-0.0803010008086803,
		-0.0843542844395502,
		-0.08289997652902,
		-0.0755205303205043,
		-0.0623989265477109,
		-0.044326283089366,
		-0.0226332425116305,
		 0.000947729065353350,
		 0.024472194226015150,
		 0.046001329966878411,
		 0.063818826364247711,
		 0.076618772565330132,
		 0.083640382757004264,
		 0.084733029963354578,
		 0.080344934553114006,
		 0.071439488752799568,
		 0.059352988395756881,
		 0.045615052734295655,
		 0.031757194658500076,
		 0.019135353485266245,
		 0.008788824555997565,
		 0.001351588425775887,
		-0.00297632694252734,
		-0.00439876374527305,
		-0.0034440886788769,
		-0.000852207473897706,
		 0.002553044866177805,
		 0.005986816634971998,
		 0.008804720730341286,
		 0.010570998440906138,
		 0.011087647187297713,
		 0.010385208138038017,
		 0.008681549390986811,
		 0.006319038357528510,
		 0.003692494414733371,
		 0.001180149648919237,
		-0.000912217749302234,
		-0.00238723187166376,
		-0.00316926888325945,
		-0.00329650010771388,
		-0.00289615876389169,
		-0.00214962113973893,
		-0.00125458222907089,
		-0.00039098698268249,
		 0.000304269616383307,
		 0.000751116313364406,
		 0.000928187227893370,
		 0.000864538297954332,
		 0.000624396433521362,
		 0.000288819616933416,
		-0.000061967985882062,
		-0.0003625703
};

//
//
// Same as above, but set to 90.50 degrees
//

const float q_tx_coeffs_plus[Q_NUM_TAPS] =
{
		 0.000362570336660739,
		 0.000061967985882087,
		-0.000288819616933394,
		-0.000624396433521347,
		-0.000864538297954331,
		-0.000928187227893387,
		-0.000751116313364443,
		-0.000304269616383362,
		 0.000390986982682422,
		 0.001254582229070819,
		 0.002149621139738867,
		 0.002896158763891652,
		 0.003296500107713881,
		 0.003169268883259502,
		 0.002387231871663873,
		 0.000912217749302397,
		-0.00118014964891904,
		-0.00369249441473315,
		-0.0063190383575283,
		-0.00868154939098664,
		-0.0103852081380379,
		-0.0110876471872977,
		-0.0105709984409062,
		-0.00880472073034147,
		-0.00598681663497225,
		-0.00255304486617809,
		 0.000852207473897458,
		 0.003444088678876743,
		 0.004398763745273053,
		 0.002976326942527550,
		-0.00135158842577545,
		-0.00878882455599689,
		-0.0191353534852654,
		-0.0317571946584991,
		-0.0456150527342946,
		-0.0593529883957559,
		-0.0714394887527988,
		-0.0803449345531135,
		-0.0847330299633545,
		-0.0836403827570047,
		-0.0766187725653309,
		-0.063818826364249,
		-0.04600132996688,
		-0.024472194226017,
		-0.000947729065355237,
		 0.022633242511628689,
		 0.044326283089364420,
		 0.062398926547709600,
		 0.075520530320503376,
		 0.082899976529019620,
		 0.084354284439550217,
		 0.080301000808680703,
		 0.071677864567332258,
		 0.059803097306046459,
		 0.046197303816290308,
		 0.032392309638462256,
		 0.019752786183418195,
		 0.009333296059402051,
		 0.001787082712367711,
		-0.00266537152354207,
		-0.00420893270496572,
		-0.00335665615231898,
		-0.000838253137920996,
		 0.002526925484609218,
		 0.005953056929414835,
		 0.008790299640437925,
		 0.010594423403711299,
		 0.011157627060598356,
		 0.010500966211605890,
		 0.008834492299436714,
		 0.006495333329645809,
		 0.003876032148147378,
		 0.001355384690100501,
		-0.00075796589037918,
		-0.00226228939338566,
		-0.00307703518920621,
		-0.00323573638818543,
		-0.00286195304248951,
		-0.00213476496304362,
		-0.00125106917514844,
		-0.000391369760756469,
		 0.000305860365559143,
		 0.000758399358985238,
		 0.000942618895181516,
		 0.000885595444496015,
		 0.000650132273189035,
		 0.000316545004415907,
		-0.000035020356392576,
		-0.000338712
};

//static float32_t 		FirState_Q_TX[128];
//arm_fir_instance_f32 	FIR_Q_TX;

// ******************************************************
/*
 	 * Hilbert 90 Degree, "Phase-added" bandpass filter
     * Kaiser Window FIR Filter, Beta = 4.50, Raised Cosine = 0.90
     * Fc = 1.34 kHz
     * BW = 2.59 kHz
     * 89 Taps
     * -1dB @ 586, 2262 Hz
     * -3dB @ 375, 2590 Hz
     * -6dB @ 281, 2801 Hz
     * -20dB >3350 Hz
     *
     * 20141203 by KA7OEI using Iowa Hills Hilbert Filter Designer
*/
// 90.00 degrees
//
/*
const float q_tx_coeffs[Q_NUM_TAPS] =
{
		-0.000526928409407497,
		-0.000682168851958448,
		-0.000839767578541472,
		-0.000981498412862589,
		-0.00108769943509687,
		-0.00114219260999309,
		-0.00113825881575537,
		-0.00108453094116136,
		-0.00100932782529027,
		-0.00096187275813581,
		-0.00100910869681224,
		-0.00122746365506947,
		-0.00168987888293049,
		-0.00244954977667187,
		-0.00352293473620201,
		-0.00487541234223226,
		-0.00641327332564779,
		-0.00798534440534439,
		-0.0093963912970918,
		-0.0104326182261427,
		-0.0108973047564267,
		-0.0106522625924804,
		-0.00965879884616354,
		-0.00801068418291469,
		-0.00595160530612727,
		-0.00387092484966974,
		-0.00227424342160432,
		-0.00172897224095695,
		-0.00278936501052668,
		-0.00590954769707433,
		-0.0113562931550096,
		-0.0191349550525017,
		-0.0289416425545354,
		-0.0401522247733495,
		-0.0518542997346794,
		-0.0629223963586435,
		-0.0721302338128361,
		-0.0782878354349201,
		-0.0803866797961855,
		-0.0777336957317831,
		-0.0700552787875277,
		-0.0575557105123902,
		-0.040920032384147,
		-0.0212587852711883,
		-879.3219467956480E-18,
		 0.021258785271186593,
		 0.040920032384145433,
		 0.057555710512388988,
		 0.070055278787526834,
		 0.077733695731782626,
		 0.080386679796185356,
		 0.078287835434920336,
		 0.072130233812836633,
		 0.062922396358644245,
		 0.051854299734680302,
		 0.040152224773350405,
		 0.028941642554536236,
		 0.019134955052502414,
		 0.011356293155010121,
		 0.005909547697074680,
		 0.002789365010526848,
		 0.001728972240956973,
		 0.002274243421604222,
		 0.003870924849669563,
		 0.005951605306127063,
		 0.008010684182914484,
		 0.009658798846163363,
		 0.010652262592480283,
		 0.010897304756426593,
		 0.010432618226142680,
		 0.009396391297091819,
		 0.007985344405344439,
		 0.006413273325647856,
		 0.004875412342232334,
		 0.003522934736202069,
		 0.002449549776671917,
		 0.001689878882930529,
		 0.001227463655069487,
		 0.001009108696812252,
		 0.000961872758135811,
		 0.001009327825290265,
		 0.001084530941161355,
		 0.001138258815755372,
		 0.001142192609993090,
		 0.001087699435096872,
		 0.000981498412862595,
		 0.000839767578541479,
		 0.000682168851958454,
		 0.000526928409407502
};
*/
//
// Same as above, but set to 89.50 degrees
//
/*
const float q_tx_coeffs_minus[Q_NUM_TAPS] =
{
		-0.000528590955246896,
		-0.000683737107044304,
		-0.00084096480894464,
		-0.000982057737507664,
		-0.00108745058029202,
		-0.00114116183748396,
		-0.00113676125174238,
		-0.00108322913101734,
		-0.00100922969391004,
		-0.000964247788333325,
		-0.00101531346505587,
		-0.00123868584127438,
		-0.00170682989844849,
		-0.0024721563156369,
		-0.00355009420513846,
		-0.00490488175478613,
		-0.00644175250042284,
		-0.0080087909037941,
		-0.00941056798239429,
		-0.0104338290941965,
		-0.0108832278859864,
		-0.0106227494380667,
		-0.00961648561330794,
		-0.00796126112423059,
		-0.00590361771033709,
		-0.00383503502684369,
		-0.00226196077819069,
		-0.00175094842590231,
		-0.00285343933402063,
		-0.00601879924676511,
		-0.0115073959275739,
		-0.0193171303014972,
		-0.0291364536732455,
		-0.0403343669834117,
		-0.0519934098475785,
		-0.062985763675961,
		-0.0720861528497252,
		-0.078109226669877,
		-0.0800545356162499,
		-0.0772398987833597,
		-0.0694043941923696,
		-0.0567654672312946,
		-0.0400203683100041,
		-0.0202895137406024,
		 0.000992663698347939,
		 0.022226446510772688,
		 0.041816596885146190,
		 0.058341594116229086,
		 0.070700856899577724,
		 0.078221604579403414,
		 0.080712734919510698,
		 0.078460514124693917,
		 0.072168851121047067,
		 0.062854262853266063,
		 0.051711261809768518,
		 0.039967041149333880,
		 0.028744639190788065,
		 0.018951330386453736,
		 0.011204330176351016,
		 0.005799848516376376,
		 0.002725079400766322,
		 0.001706865091405545,
		 0.002286353797709707,
		 0.003906521461224742,
		 0.005999142085168465,
		 0.008059500455628572,
		 0.009700380453168631,
		 0.010680968869061515,
		 0.010910556187804959,
		 0.010430617117676766,
		 0.009381502862545733,
		 0.007961293040338978,
		 0.006384308364117642,
		 0.004845573631408834,
		 0.003495508415231204,
		 0.002426757691453475,
		 0.001672799864014351,
		 0.001216148492071635,
		 0.001002827491527114,
		 0.000959424868881409,
		 0.001009349503030634,
		 0.001085750601248764,
		 0.001139670159981910,
		 0.001143136864742313,
		 0.001087865899840933,
		 0.000980864742574511,
		 0.000838506738192757,
		 0.000680548924571070,
		 0.000525225950277461
};
*/
//
//
// Same as above, but set to 90.50 degrees
//
/*
const float q_tx_coeffs_plus[Q_NUM_TAPS] =
{
		-0.000525225950277457,
		-0.000680548924571068,
		-0.000838506738192757,
		-0.000980864742574515,
		-0.00108786589984094,
		-0.00114313686474233,
		-0.00113967015998193,
		-0.00108575060124878,
		-0.00100934950303065,
		-0.000959424868881421,
		-0.00100282749152711,
		-0.00121614849207162,
		-0.00167279986401431,
		-0.00242675769145341,
		-0.00349550841523112,
		-0.00484557363140873,
		-0.00638430836411753,
		-0.00796129304033888,
		-0.00938150286254566,
		-0.0104306171176767,
		-0.010910556187805,
		-0.0106809688690616,
		-0.00970038045316875,
		-0.00805950045562874,
		-0.00599914208516865,
		-0.0039065214612249,
		-0.00228635379770981,
		-0.00170686509140555,
		-0.00272507940076618,
		-0.00579984851637607,
		-0.0112043301763505,
		-0.0189513303864531,
		-0.0287446391907873,
		-0.039967041149333,
		-0.0517112618097677,
		-0.0628542628532654,
		-0.0721688511210466,
		-0.0784605141246937,
		-0.0807127349195108,
		-0.0782216045794039,
		-0.0707008568995786,
		-0.0583415941162303,
		-0.0418165968851477,
		-0.0222264465107743,
		-0.000992663698349638,
		 0.020289513740600736,
		 0.040020368310002608,
		 0.056765467231293443,
		 0.069404394192368740,
		 0.077239898783359171,
		 0.080054535616249756,
		 0.078109226669877185,
		 0.072086152849725707,
		 0.062985763675961690,
		 0.051993409847579261,
		 0.040334366983412563,
		 0.029136453673246278,
		 0.019317130301497797,
		 0.011507395927574344,
		 0.006018799246765419,
		 0.002853439334020776,
		 0.001750948425902314,
		 0.002261960778190588,
		 0.003835035026843535,
		 0.005903617710336912,
		 0.007961261124230424,
		 0.009616485613307815,
		 0.010622749438066646,
		 0.010883227885986375,
		 0.010433829094196524,
		 0.009410567982394365,
		 0.008008790903794199,
		 0.006441752500422943,
		 0.004904881754786236,
		 0.003550094205138550,
		 0.002472156315636968,
		 0.001706829898448527,
		 0.001238685841274393,
		 0.001015313465055867,
		 0.000964247788333315,
		 0.001009229693910023,
		 0.001083229131017316,
		 0.001136761251742360,
		 0.001141161837483949,
		 0.001087450580292008,
		 0.000982057737507660,
		 0.000840964808944640,
		 0.000683737107044306,
		 0.000528590955246900
};
*/





#endif
