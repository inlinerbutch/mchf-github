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

#ifndef __Q_RX_FILTER_H
#define __Q_RX_FILTER_H

#define Q_BLOCK_SIZE		1
#define Q_NUM_TAPS			89

/*
 	 * Hilbert 90 Degree, "Phase-added" bandpass filter
     * Kaiser Window FIR Filter, Beta = 3.25, Raised Cosine = 9.30
     * Fc = 5.23 kHz
     * BW = 9.50 kHz
     * 89 Taps
     *
     * 20140926 by KA7OEI using Iowa Hills Hilbert Filter Designer
*/

const float q_rx_coeffs[Q_NUM_TAPS] =
{
		 0.000344914318465872,
		 0.001232705528752468,
		 0.000944100782885026,
		-0.000373513290057777,
		-0.000696848846812344,
		 0.000867087438645400,
		 0.002144828909072224,
		 0.000801938000274561,
		-0.00162900365360321,
		-0.00135050947432204,
		 0.001735480576860600,
		 0.002902894907756880,
		-0.000514482236669199,
		-0.00408390144313164,
		-0.00214047204883299,
		 0.002895860450918038,
		 0.002787523104742692,
		-0.00393491877494282,
		-0.00805973561226184,
		-0.00288287943428056,
		 0.004054650295992699,
		 0.000625965609562838,
		-0.010618675078802,
		-0.0137682376952537,
		-0.00334152729361202,
		 0.004534947238988187,
		-0.00542579685174649,
		-0.0221939015821796,
		-0.0214720818837083,
		-0.00330493087662929,
		 0.002966766270241431,
		-0.0188306615843171,
		-0.0421097245423961,
		-0.032297456691877,
		-0.00266967518669887,
		-0.00406851387698861,
		-0.0498846435725893,
		-0.0835255465990852,
		-0.0529683656275652,
		-0.00149470600381967,
		-0.0342346563886709,
		-0.175133004530271,
		-0.296357122291255,
		-0.238667384668651,
		-11.00502419074730E-15,
		 0.238667384668637877,
		 0.296357122291259212,
		 0.175133004530283742,
		 0.034234656388678494,
		 0.001494706003817782,
		 0.052968365627560861,
		 0.083525546599085732,
		 0.049884643572593541,
		 0.004068513876990715,
		 0.002669675186696901,
		 0.032297456691874740,
		 0.042109724542396962,
		 0.018830661584319623,
		-0.00296676627024075,
		 0.003304930876627653,
		 0.021472081883707091,
		 0.022193901582180590,
		 0.005425796851748176,
		-0.00453494723898796,
		 0.003341527293610915,
		 0.013768237695253149,
		 0.010618675078802686,
		-0.000625965609562042,
		-0.00405465029599303,
		 0.002882879434279615,
		 0.008059735612261585,
		 0.003934918774943465,
		-0.00278752310474217,
		-0.00289586045091835,
		 0.002140472048832366,
		 0.004083901443131590,
		 0.000514482236669776,
		-0.0029028949077564,
		-0.00173548057686072,
		 0.001350509474321610,
		 0.001629003653603014,
		-0.000801938000274391,
		-0.00214482890907199,
		-0.000867087438645351,
		 0.000696848846812240,
		 0.000373513290057688,
		-0.000944100782885024,
		-0.0012327055287524,
		-0.00034491431846579
};
//
// Same as above, but set to 89.50 degrees
//
const float q_rx_coeffs_minus[Q_NUM_TAPS] =
{
		 0.000345785684615153,
		 0.001228151699489135,
		 0.000928609842354247,
		-0.000390036613399047,
		-0.000701868547077255,
		 0.000867085470047767,
		 0.002129637897587250,
		 0.000768623936932851,
		-0.00165643444349555,
		-0.00135558008964599,
		 0.001731094482962856,
		 0.002866474588417179,
		-0.000573927606884969,
		-0.0041212503195128,
		-0.00214277924812288,
		 0.002879904843097448,
		 0.002715603103600132,
		-0.00402654767723954,
		-0.00810046470178972,
		-0.00287882095109734,
		 0.004014830102304475,
		 0.000501798670783072,
		-0.0107425398973817,
		-0.0137978008744989,
		-0.00332772062420192,
		 0.004451986134975294,
		-0.00562016370473348,
		-0.0223394733877002,
		-0.021464244807311,
		-0.00327942625837146,
		 0.002809540973692196,
		-0.019115999589606,
		-0.0422483507953672,
		-0.0322027408364947,
		-0.00263291508566302,
		-0.00436440365302093,
		-0.0503020108880629,
		-0.0835820932848714,
		-0.0526480101213734,
		-0.0014498070570843,
		-0.034935857092474,
		-0.175929457378993,
		-0.295818803277577,
		-0.236108308594669,
		 0.003529442209628497,
		 0.241208304736372586,
		 0.296872896700565492,
		 0.174323228889556564,
		 0.033530851371612519,
		 0.001539491244645685,
		 0.053284691701835890,
		 0.083462645922585635,
		 0.049463481411411839,
		 0.003772314599249648,
		 0.002706232199072596,
		 0.032389715601469069,
		 0.041967894900647146,
		 0.018543891084976949,
		-0.00312376587769128,
		 0.003330184080785761,
		 0.021478285526808173,
		 0.022046641432790341,
		 0.005231017245247858,
		-0.00461756335857612,
		 0.003355079764943195,
		 0.013737627132805703,
		 0.010494002471880374,
		-0.00075008492962116,
		-0.00409416204260874,
		 0.002886718609838992,
		 0.008018393399116761,
		 0.003842990533841140,
		-0.00285923105224792,
		-0.0029115957636177,
		 0.002138002018647314,
		 0.004046241894472272,
		 0.000454997728543658,
		-0.0029390943968467,
		-0.00173973464854587,
		 0.001345336122469638,
		 0.001601448941455631,
		-0.000835191058249309,
		-0.00215985675822488,
		-0.000867023445800554,
		 0.000691776135567074,
		 0.000356961552655413,
		-0.000959519903381672,
		-0.00123716558311929,
		-0.000344016713848569
};
//
//
// Same as above, but set to 90.50 degrees
//
const float q_rx_coeffs_plus[Q_NUM_TAPS] =
{
		 0.000344016713848422,
		 0.001237165583119233,
		 0.000959519903381830,
		-0.000356961552655221,
		-0.000691776135567152,
		 0.000867023445800239,
		 0.002159856758224740,
		 0.000835191058249567,
		-0.0016014489414553,
		-0.00134533612246971,
		 0.001739734648545488,
		 0.002939094396846569,
		-0.00045499772854331,
		-0.00404624189447194,
		-0.00213800201864746,
		 0.002911595763617357,
		 0.002859231052247991,
		-0.0038429905338407,
		-0.00801839339911664,
		-0.00288671860983938,
		 0.004094162042608576,
		 0.000750084929621739,
		-0.0104940024718798,
		-0.013737627132806,
		-0.00335507976494403,
		 0.00461756335857628,
		-0.00523101724524657,
		-0.0220466414327896,
		-0.0214782855268092,
		-0.00333018408078714,
		 0.003123765877691971,
		-0.0185438910849747,
		-0.0419678949006465,
		-0.0323897156014713,
		-0.00270623219907439,
		-0.00377231459924747,
		-0.0494634814114077,
		-0.0834626459225853,
		-0.0532846917018405,
		-0.00153949124464774,
		-0.0335308513716049,
		-0.174323228889544,
		-0.296872896700561,
		-0.241208304736386,
		-0.00352944220965053,
		 0.236108308594655258,
		 0.295818803277580589,
		 0.175929457379005394,
		 0.034935857092481731,
		 0.001449807057082345,
		 0.052648010121368764,
		 0.083582093284871553,
		 0.050302010888066989,
		 0.004364403653023157,
		 0.002632915085661265,
		 0.032202740836492459,
		 0.042248350795367859,
		 0.019115999589608253,
		-0.00280954097369148,
		 0.003279426258370093,
		 0.021464244807309917,
		 0.022339473387700919,
		 0.005620163704734763,
		-0.00445198613497516,
		 0.003327720624201085,
		 0.013797800874498599,
		 0.010742539897382350,
		-0.000501798670782488,
		-0.00401483010230463,
		 0.002878820951096947,
		 0.008100464701789833,
		 0.004026547677239973,
		-0.00271560310360006,
		-0.00287990484309779,
		 0.002142779248122731,
		 0.004121250319513134,
		 0.000573927606885321,
		-0.0028664745884173,
		-0.00173109448296324,
		 0.001355580089645912,
		 0.001656434443495877,
		-0.000768623936932588,
		-0.00212963789758739,
		-0.000867085470048082,
		 0.000701868547077172,
		 0.000390036613399236,
		-0.000928609842354086,
		-0.00122815169948919,
		-0.0003457857
};

/*
static float32_t 		FirState_Q[128];
arm_fir_instance_f32 	FIR_Q;
*/
#endif
