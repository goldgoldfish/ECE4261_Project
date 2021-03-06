#pragma line 1 "blowfish_decipher/blowfish_decrypt_ap_cntrl.c"
#pragma line 1 "blowfish_decipher/blowfish_decrypt_ap_cntrl.c" 1
#pragma line 1 "<built-in>" 1
#pragma line 1 "<built-in>" 3
#pragma line 148 "<built-in>" 3
#pragma line 1 "<command line>" 1
#pragma empty_line
#pragma empty_line
#pragma empty_line
#pragma empty_line
#pragma empty_line
#pragma line 1 "C:/Xilinx2017.1/Vivado_HLS/2017.1/common/technology/autopilot\\etc/autopilot_ssdm_op.h" 1
/* autopilot_ssdm_op.h*/
/*
#-  (c) Copyright 2011-2017 Xilinx, Inc. All rights reserved.
#-
#-  This file contains confidential and proprietary information
#-  of Xilinx, Inc. and is protected under U.S. and
#-  international copyright and other intellectual property
#-  laws.
#-
#-  DISCLAIMER
#-  This disclaimer is not a license and does not grant any
#-  rights to the materials distributed herewith. Except as
#-  otherwise provided in a valid license issued to you by
#-  Xilinx, and to the maximum extent permitted by applicable
#-  law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
#-  WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
#-  AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
#-  BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
#-  INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
#-  (2) Xilinx shall not be liable (whether in contract or tort,
#-  including negligence, or under any other theory of
#-  liability) for any loss or damage of any kind or nature
#-  related to, arising under or in connection with these
#-  materials, including for any direct, or any indirect,
#-  special, incidental, or consequential loss or damage
#-  (including loss of data, profits, goodwill, or any type of
#-  loss or damage suffered as a result of any action brought
#-  by a third party) even if such damage or loss was
#-  reasonably foreseeable or Xilinx had been advised of the
#-  possibility of the same.
#-
#-  CRITICAL APPLICATIONS
#-  Xilinx products are not designed or intended to be fail-
#-  safe, or for use in any application requiring fail-safe
#-  performance, such as life-support or safety devices or
#-  systems, Class III medical devices, nuclear facilities,
#-  applications related to the deployment of airbags, or any
#-  other applications that could lead to death, personal
#-  injury, or severe property or environmental damage
#-  (individually and collectively, "Critical
#-  Applications"). Customer assumes the sole risk and
#-  liability of any use of Xilinx products in Critical
#-  Applications, subject only to applicable laws and
#-  regulations governing limitations on product liability.
#-
#-  THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
#-  PART OF THIS FILE AT ALL TIMES. 
#- ************************************************************************
#pragma empty_line
 *
 * $Id$
 */
#pragma line 289 "C:/Xilinx2017.1/Vivado_HLS/2017.1/common/technology/autopilot\\etc/autopilot_ssdm_op.h"
/*#define AP_SPEC_ATTR __attribute__ ((pure))*/
#pragma empty_line
#pragma empty_line
#pragma empty_line
    /****** SSDM Intrinsics: OPERATIONS ***/
    // Interface operations
    //typedef unsigned int __attribute__ ((bitwidth(1))) _uint1_;
    void _ssdm_op_IfRead() __attribute__ ((nothrow));
    void _ssdm_op_IfWrite() __attribute__ ((nothrow));
    //_uint1_ _ssdm_op_IfNbRead() SSDM_OP_ATTR;
    //_uint1_ _ssdm_op_IfNbWrite() SSDM_OP_ATTR;
    //_uint1_ _ssdm_op_IfCanRead() SSDM_OP_ATTR;
    //_uint1_ _ssdm_op_IfCanWrite() SSDM_OP_ATTR;
#pragma empty_line
    // Stream Intrinsics
    void _ssdm_StreamRead() __attribute__ ((nothrow));
    void _ssdm_StreamWrite() __attribute__ ((nothrow));
    //_uint1_  _ssdm_StreamNbRead() SSDM_OP_ATTR;
    //_uint1_  _ssdm_StreamNbWrite() SSDM_OP_ATTR;
    //_uint1_  _ssdm_StreamCanRead() SSDM_OP_ATTR;
    //_uint1_  _ssdm_StreamCanWrite() SSDM_OP_ATTR;
#pragma empty_line
    // Misc
    void _ssdm_op_MemShiftRead() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_Wait() __attribute__ ((nothrow));
    void _ssdm_op_Poll() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_Return() __attribute__ ((nothrow));
#pragma empty_line
    /* SSDM Intrinsics: SPECIFICATIONS */
    void _ssdm_op_SpecSynModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecTopModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDecl() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDef() __attribute__ ((nothrow));
    void _ssdm_op_SpecPort() __attribute__ ((nothrow));
    void _ssdm_op_SpecConnection() __attribute__ ((nothrow));
    void _ssdm_op_SpecChannel() __attribute__ ((nothrow));
    void _ssdm_op_SpecSensitive() __attribute__ ((nothrow));
    void _ssdm_op_SpecModuleInst() __attribute__ ((nothrow));
    void _ssdm_op_SpecPortMap() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_SpecReset() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_SpecPlatform() __attribute__ ((nothrow));
    void _ssdm_op_SpecClockDomain() __attribute__ ((nothrow));
    void _ssdm_op_SpecPowerDomain() __attribute__ ((nothrow));
#pragma empty_line
    int _ssdm_op_SpecRegionBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecRegionEnd() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_SpecLoopName() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_SpecLoopTripCount() __attribute__ ((nothrow));
#pragma empty_line
    int _ssdm_op_SpecStateBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecStateEnd() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_SpecInterface() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_SpecPipeline() __attribute__ ((nothrow));
    void _ssdm_op_SpecDataflowPipeline() __attribute__ ((nothrow));
#pragma empty_line
#pragma empty_line
    void _ssdm_op_SpecLatency() __attribute__ ((nothrow));
    void _ssdm_op_SpecParallel() __attribute__ ((nothrow));
    void _ssdm_op_SpecProtocol() __attribute__ ((nothrow));
    void _ssdm_op_SpecOccurrence() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_SpecResource() __attribute__ ((nothrow));
    void _ssdm_op_SpecResourceLimit() __attribute__ ((nothrow));
    void _ssdm_op_SpecCHCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecFUCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIFCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIPCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecKeepValue() __attribute__ ((nothrow));
    void _ssdm_op_SpecMemCore() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_SpecExt() __attribute__ ((nothrow));
    /*void* _ssdm_op_SpecProcess() SSDM_SPEC_ATTR;
    void* _ssdm_op_SpecEdge() SSDM_SPEC_ATTR; */
#pragma empty_line
    /* Presynthesis directive functions */
    void _ssdm_SpecArrayDimSize() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_RegionBegin() __attribute__ ((nothrow));
    void _ssdm_RegionEnd() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_Unroll() __attribute__ ((nothrow));
    void _ssdm_UnrollRegion() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_InlineAll() __attribute__ ((nothrow));
    void _ssdm_InlineLoop() __attribute__ ((nothrow));
    void _ssdm_Inline() __attribute__ ((nothrow));
    void _ssdm_InlineSelf() __attribute__ ((nothrow));
    void _ssdm_InlineRegion() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_SpecArrayMap() __attribute__ ((nothrow));
    void _ssdm_SpecArrayPartition() __attribute__ ((nothrow));
    void _ssdm_SpecArrayReshape() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_SpecStream() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_SpecExpr() __attribute__ ((nothrow));
    void _ssdm_SpecExprBalance() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_SpecDependence() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_SpecLoopMerge() __attribute__ ((nothrow));
    void _ssdm_SpecLoopFlatten() __attribute__ ((nothrow));
    void _ssdm_SpecLoopRewind() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_SpecFuncInstantiation() __attribute__ ((nothrow));
    void _ssdm_SpecFuncBuffer() __attribute__ ((nothrow));
    void _ssdm_SpecFuncExtract() __attribute__ ((nothrow));
    void _ssdm_SpecConstant() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_DataPack() __attribute__ ((nothrow));
    void _ssdm_SpecDataPack() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_SpecBitsMap() __attribute__ ((nothrow));
    void _ssdm_op_SpecLicense() __attribute__ ((nothrow));
#pragma empty_line
#pragma empty_line
/*#define _ssdm_op_WaitUntil(X) while (!(X)) _ssdm_op_Wait(1);
#define _ssdm_op_Delayed(X) X */
#pragma line 427 "C:/Xilinx2017.1/Vivado_HLS/2017.1/common/technology/autopilot\\etc/autopilot_ssdm_op.h"
// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#pragma line 7 "<command line>" 2
#pragma line 1 "<built-in>" 2
#pragma line 1 "blowfish_decipher/blowfish_decrypt_ap_cntrl.c" 2
#pragma empty_line
#pragma empty_line
#pragma empty_line
unsigned long S[4][256] =
{
  {827466583, 1160073249, 834734275, 1879080055, 82060437, 1888704483, 822177859, 1169587125, 827466583, 1884499811, 79132545, 1957956342, 891694422, 1172646049, 74911489, 1891632375, 827466583, 1160073249, 834734275, 1879080055, 82060437, 1948721506, 901056194, 1169587125, 69491733, 1884499811, 834734275, 1165361973, 831675351, 1888704483, 74911489, 1953788534, 904287702, 1160073249, 79132545, 1879080055, 831675351, 1172646049, 822177859, 1891632375, 69491733, 1961318882, 896892482, 1165361973, 82060437, 1888704483, 822177859, 1169587125, 827466583, 1884499811, 79132545, 1957956342, 831675351, 891686278, 1879071911, 1090653492, 1160081649, 1961318882, 79107889, 1957956342, 1888688003, 5247604, 1103246804, 1090678148, 69483685, 69475445, 74936145, 1879080055, 1961327058, 831683335, 1883296935, 205264, 1892917091, 73700469, 1962189510, 4442496, 831675351, 13689364, 83337169, 1161227109, 13673108, 835908583, 70772561, 70764385, 835900375, 895935798, 1953772278, 1953788534, 77909189, 9464564, 901056034, 830586947, 9448052, 1091679888, 901080690, 896884370, 69491733, 827458439, 1173803877, 74919889, 1952966914, 1880336259, 1165370341, 826390723, 835892103, 73725125, 83361665, 1887497383, 82060437, 900136422, 1099095396, 834750627, 891694518, 1095851712, 1161210629, 4442496, 1164286113, 1880344371, 892712514, 1103263204, 9439940, 900136374, 83353441, 205104, 1160081425, 1961302498, 892704274, 1953788614, 1100039712, 1112724, 1173803989, 1879080135, 891686326, 1095843472, 213424, 901072450, 82076821, 9464388, 1169570661, 1962189334, 891694566, 1961310642, 1090653524, 213344, 1172662305, 1888696243, 901072578, 1094878564, 1112644, 891686198, 74919905, 8638896, 1168474257, 1952967010, 901080722, 1962181190, 1091679904, 9439764, 1165370197, 1887472711, 900136246, 1104268816, 8630576, 892712642, 73700373, 1088196, 1161219045, 1953780374, 900128102, 1952958770, 1099103700, 8630752, 1164286113, 1880344371, 892712514, 1103263204, 9439940, 900136374, 83353441, 205104, 1160081425, 1961302498, 892704274, 1953788614, 1100039712, 1112724, 1173803989, 1879080135, 891686326, 1095843472, 213424, 901072450, 82076821, 9464388, 1169570661, 1962189334, 891694566, 1961310642, 1090653524, 213344, 1172662305, 1888696243, 901072578, 1094878564, 1112644, 891686198, 74919905, 8638896, 1168474257, 1952967010, 901080722, 1962181190, 1091679904, 9439764, 1165370197, 1887472711, 900136246, 1104268816, 8630576, 892712642, 73700373, 1088196, 1161219045, 1953780374, 900128102, 1952958770, 1099103700, 8630752, 1164286113, 1880344371, 892712514, 1103263204, 9439940, 900136374, 83353441, 205104, 1160081425, 1961302498, 892704274, 1953788614, 1100039712, 1112724, 1173803989, 1879080135, 891686326, 1095843472, 213424, 901072450, 82076821, 9464388, 1169570661, 1962189334, 891694566, 1961310642, 1090653524, 213344},
  {1172662305, 1888696243, 1161193507, 905293474, 1450569046, 880499058, 1464112614, 666274433, 1653644240, 626676645, 1438991654, 1467289430, 595750624, 1386370901, 446157408, 2952519520, 3543243254, 1857254082, 1877008854, 3608560803, 2798254768, 1848877602, 437699264, 519196130, 4281488642, 1813850164, 2508101618, 1900770103, 1970138626, 2717718038, 3185988274, 29946304, 1125024644, 760076199, 1756972450, 2447929073, 2440799589, 3648992045, 2854665774, 3278913498, 1671412139, 3335988228, 2967504514, 3153389662, 3145423182, 3884225933, 2732411768, 3127878346, 2383107692, 911070855, 251071069, 1773199929, 3118383499, 603243872, 3527205024, 4188264173, 464128582, 4044507582, 3749328469, 4207564458, 3139264909, 3586074608, 2366925559, 1708382885, 352899396, 2993271602, 1735804768, 493217997, 1559719533, 1738902500, 3770246701, 1533236206, 2747956961, 1406263517, 937807529, 2737020153, 610312249, 356669535, 3975391194, 3705223609, 2684996139, 1886871718, 2571105342, 962711498, 2752547588, 828834342, 3760646860, 1306497949, 4086769135, 4225567260, 1407919588, 771471081, 84204071, 1367359217, 3382777248, 2653603443, 863858496, 1731699523, 2387749194, 3124113968, 1339942655, 3799021021, 1472112259, 3583141533, 1532415435, 361915284, 158656788, 310910627, 3282237723, 2919691356, 3906792703, 2867026576, 3856271086, 1346170996, 3932573361, 1734937407, 3470056113, 2011342831, 2428451629, 1726245599, 210203937, 2418823529, 317750184, 2857219178, 3561394039, 916894404, 1272850512, 2997550290, 1191148499, 3789681887, 621068485, 79293184, 1773073765, 1161776600, 1735338481, 4085219303, 1277305111, 130935180, 2980000537, 849059146, 2848493337, 4225213038, 2514017876, 4065651327, 3338032542, 159052112, 3350763023, 920401442, 853978902, 20758153, 3430914986, 734539161, 280822655, 568342991, 3173997910, 295748095, 603984349, 218893139, 1857945217, 3036032693, 3361729753, 2661788432, 1351121034, 977903988, 2036416605, 1822032623, 1282536135, 2291314890, 1705716415, 1828869827, 3542922607, 3732917172, 1731792681, 1076230416, 2451321899, 909870370, 684617759, 1542614513, 1369835199, 2995582343, 203810927, 727091379, 1107892451, 585011839, 1696605052, 4053258692, 465444040, 779571898, 1255057016, 2279747169, 2100845987, 2743391739, 1954933043, 455924586, 3893826, 3529000700, 2208796414, 2796081685, 617817949, 1677770096, 2889442865, 2231401911, 811229387, 2053684014, 1830374789, 3578486156, 2913964140, 1117773991, 1997415410, 528551685, 1807568849, 3514321724, 73757263, 3493496830, 1575607852, 2397993354, 257318501, 3976199802, 1436205701, 2519135648, 2324004355, 2042709715, 4152620607, 1199686710, 95349765, 2909107830, 2705442357, 3122312064, 3795527963, 1158686073, 1453318949, 3753137026, 2370021649, 824676271, 2259170781, 1608368797, 905467579, 4035248272, 1727729255, 160787651, 3248380801, 3690515462, 1204743059, 4022683968, 285490751, 1726864716, 4182706645, 3537202678, 4155428893, 168992670, 1630199843, 1560440830, 3670448424, 336574889, 2808200986, 3032052897},
  {1176335462, 2455368099, 3720988862, 14576165, 2584267618, 751043831, 709877409, 481776053, 620146562, 2154187176, 3918479162, 2170150776, 611410603, 3506699196, 2087791700, 3962240933, 3229497830, 1268360105, 501871594, 2016514649, 1348853479, 1042899674, 2115904660, 1336126701, 1466226362, 4080295605, 3338899671, 3497806737, 638828038, 3253784145, 994312073, 614546140, 2254636458, 3088331882, 1119069711, 2791559682, 1639802349, 3778690412, 2804827949, 2558160463, 338185152, 1635216459, 1365938132, 1513819212, 2319641334, 3051874353, 2710171415, 1147981942, 3313576151, 976210726, 2386108405, 539785590, 3896658148, 3837587868, 354266447, 2833120955, 36262836, 3754301203, 1535809409, 1823411697, 2627653233, 398668255, 2052088244, 2636244719, 3399347029, 314564355, 3094636475, 1475572725, 1077953662, 950714343, 3389457961, 878472624, 2098061735, 3728966549, 476211806, 2777326370, 1379167616, 1848604198, 1415824752, 4088796421, 1440797534, 2560108368, 3306416659, 3192493206, 238874929, 2496419930, 243996324, 3278728475, 4220246511, 2624293964, 1376162815, 1837458334, 2190144968, 1002910347, 1082815351, 4007912489, 1738694186, 2590506055, 2166124430, 4167239085, 4107039990, 3921326475, 2436333445, 4251577576, 2568770880, 720504135, 1628950629, 809411787, 3428982494, 2019865572, 4082028917, 3381589782, 2740465341, 2210842995, 2514908445, 2880288928, 895468769, 850444748, 3104932783, 2339239746, 1343724637, 1936935490, 47505393, 1884592822, 2741121598, 1317816932, 2806102169, 1474811947, 1957523897, 3383554522, 2743931257, 2453902212, 3831097021, 1539301321, 510609788, 1930025183, 3867534689, 1482585720, 2281442649, 3249576906, 247586452, 2466477781, 1433986609, 1205397520, 2187957479, 2911730279, 1472863587, 2984533769, 3176473889, 4231502933, 3371562451, 651515629, 2478220561, 1841569355, 1884987090, 3696650349, 186704289, 934333114, 532557208, 2349703641, 1223891415, 3892619026, 2659224168, 1258212436, 1733466150, 1483374817, 2106772556, 906831721, 2968393063, 231164920, 4037953049, 770653029, 2275513899, 4081294286, 1272028726, 3816775688, 838259622, 3411160465, 1187097455, 2337428451, 2639452678, 3865557673, 1834882210, 99129345, 882056315, 4220497154, 1429961412, 3730551595, 4069218404, 3699634474, 3672544831, 2141466736, 2643908099, 3866533565, 1872269610, 881951109, 2124864516, 3226281210, 758278313, 3940664525, 1382636972, 1729732698, 3252729385, 1319699704, 2253117722, 2161009296, 1745294272, 3811068487, 4072081324, 594873504, 1392219947, 1567829478, 2650649111, 2709262397, 4204518954, 2582706912, 93526230, 3091540747, 3910908335, 3469004736, 222214509, 3968701215, 3249420968, 3960825898, 1002561666, 2199565763, 285486070, 4072036052, 3165528385, 3554892054, 3663447203, 1065237965, 771111838, 3928076742, 3155789604, 375620056, 606323135, 2241929884, 4168651603, 2833896178, 2847371453, 3336507218, 933320392, 2654086892, 3552720257, 2830133351, 1452435533, 2977328133, 278324344, 1713986086, 754224808, 1432466080, 3184549347, 2013304230, 3170649462, 2218215849},
  {200264797, 2632098726, 1463894064, 1633293398, 1089957238, 1407682387, 2922619538, 2046834350, 2640712551, 4015180167, 1015619060, 2946125095, 3806229528, 4113272428, 1955428532, 82438405, 2539132998, 3572586962, 4243782933, 2360697192, 824940269, 2461227861, 817965376, 2029083132, 2362609010, 2936745252, 1413374609, 2054200800, 2840957585, 714532321, 2447887450, 1423782979, 4178343103, 3160690613, 2463983142, 715257383, 1132035062, 3326857621, 28870982, 1523750034, 1437455853, 1575716329, 1916406732, 2512433010, 1642350541, 1227445378, 2634429275, 2409929233, 2254163820, 520924377, 1302023170, 3890354544, 2450517340, 3991016156, 848712016, 369941186, 3449326604, 4111157365, 3021786640, 2166089991, 556490989, 3550833748, 1417289262, 113514545, 480452969, 1986968658, 4039899057, 3758012004, 3896058252, 933958529, 1488211382, 484413073, 2864051648, 2948676238, 636954268, 1172202496, 1048779790, 1679222889, 2458280013, 4290809944, 2115193023, 767545073, 1824777184, 2990788548, 4277445517, 2244642809, 510845662, 2239545262, 3718886898, 3260356756, 982370661, 2723522918, 102688976, 956882578, 1553919781, 852349803, 2587429820, 2177969201, 2520688132, 2359683566, 63464763, 2873403943, 1628873602, 1498611573, 1679132550, 3083788034, 3911880386, 4019783484, 591089921, 3576697699, 521116717, 410395105, 1275271748, 1597438583, 535477859, 2363598152, 3009445721, 1420119779, 827925956, 2558931041, 3259882797, 3441442145, 1692709054, 3392912771, 170453320, 2057965585, 1160128717, 1771750078, 2314476998, 2024916783, 3012481632, 883754476, 2573231973, 4236466527, 288295404, 1436808146, 1192321592, 239528175, 1368897607, 2420577883, 4005643116, 1321043554, 3310588151, 1146528586, 663739788, 2359969475, 3315357231, 1953594973, 3434906652, 802796063, 2331708120, 3476870558, 3378152088, 1379957051, 3514042313, 4134965455, 2368416248, 2172084591, 1442552977, 4077517289, 4004925696, 4084498215, 1126190159, 3158500789, 2035552505, 2126631787, 4108059048, 2233221451, 104655620, 1499908121, 2428141549, 1796435313, 1619062926, 1496406392, 592869440, 1380867350, 3915589698, 3849574679, 309196929, 3837354731, 987408837, 3281021408, 4167419420, 505775751, 2324132677, 2380514386, 1687800690, 2772976669, 1465455037, 1140830992, 1552397454, 1487152833, 3357520402, 4233060117, 249235212, 1591304481, 2431948446, 3149073347, 148960264, 2741837136, 3052171381, 965765011, 1562189487, 140154460, 2331646844, 3953857284, 4015054108, 784431066, 1376988924, 2598504813, 2676113493, 3093496323, 2030871806, 1354182630, 2763903867, 2319993795, 2670372730, 3266665441, 2562277487, 1733205337, 1426832906, 2210800597, 871110244, 249060570, 2745641667, 1897796445, 1242638982, 3115832937, 1856066502, 1528070188, 1943897221, 893289327, 1876520090, 2250633519, 2627554132, 4146493225, 2310109166, 2659756079, 3342733872, 4185902499, 2192617146, 3670561402, 3671798009, 401193192, 2033646626, 1017472788, 3214646978, 1289380149, 1786212627, 2152590128, 355496400, 417186414, 1019128405, 1593872884, 3578837949, 740619165}
}; //end S
#pragma empty_line
unsigned long P[16 +2] = {
  891628582, 827400743, 0, 0, 74911489, 1953788534, 827466535, 1160073297, 1879080055, 196864, 0, 0, 891628582, 827400743, 0, 0, 74911489, 1953788534
}; //end P
#pragma empty_line
unsigned long F(unsigned long x)
{
   unsigned short a;
   unsigned short b;
   unsigned short c;
   unsigned short d;
   unsigned long y;
#pragma empty_line
   d = x & 0x00FF;
   x >>= 8;
   c = x & 0x00FF;
   x >>= 8;
   b = x & 0x00FF;
   x >>= 8;
   a = x & 0x00FF;
   //y = ((S[0][a] + S[1][b]) ^ S[2][c]) + S[3][d];
   y = S[0][a] + S[1][b];
   y = y ^ S[2][c];
   y = y + S[3][d];
#pragma empty_line
   return y;
}
#pragma empty_line
void Blowfish_decipher(unsigned long *xl, unsigned long *xr)
{
#pragma HLS interface s_axilite port=return
 unsigned long Xl;
   unsigned long Xr;
   unsigned long temp;
   short i;
#pragma empty_line
   Xl = *xl;
   Xr = *xr;
#pragma empty_line
   for (i = 16 + 1; i > 1; --i) {
      Xl = Xl ^ P[i];
      Xr = F(Xl) ^ Xr;
#pragma empty_line
      /* Exchange Xl and Xr */
      temp = Xl;
      Xl = Xr;
      Xr = temp;
   }
#pragma empty_line
   /* Exchange Xl and Xr */
   temp = Xl;
   Xl = Xr;
   Xr = temp;
#pragma empty_line
   Xr = Xr ^ P[1];
   Xl = Xl ^ P[0];
#pragma empty_line
   *xl = Xl;
   *xr = Xr;
}
