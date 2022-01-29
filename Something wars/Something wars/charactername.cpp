#include "charactername.hpp"
#include<sstream>

charactername::charactername() {
	
	data();

}

charactername::~charactername() {


}

void charactername::data() {

	name[0] = "Suphanut";
	name[1] = "Bedisa";
	name[2] = "Dalia";
	name[3] = "Destiny";
	name[4] = "Evangeline";
	name[5] = "Felix";
	name[6] = "Faustina";
	name[7] = "Lucky";
	name[8] = "Merrit";
	name[9] = "GGG";
	name[10] = "Venturo";
	name[11] = "Doom";
	name[12] = "Guy";
	name[13] = "Dragon";
	name[14] = "Shit";
	name[15] = "Trooper";
	name[16] = "Prayut";
	name[17] = "Hello";
	name[18] = "Slaughter";
	name[19] = "Hell-Raiser";
	name[20] = "Slammer";
	name[21] = "BadLuck";
	name[22] = "Cutto";
	name[23] = "Koh-Kae";
	name[24] = "Cream";
	name[25] = "Been";
	name[26] = "T.Thana";
	name[27] = "Hollowman";
	name[28] = "Katana";
	name[29] = "Ploy";
	name[30] = "Zweihander";
	name[31] = "Under";
	name[32] = "Falcon";
	name[33] = "Dio";
	name[34] = "Link";
	name[35] = "Jotaro_Kujo";
	name[36] = "Thanatos";
	name[37] = "Money";
	name[38] = "BeerKB431";
	name[39] = "Broadsword";
	name[40] = "Gladius";
	name[41] = "Goshawk";
	name[42] = "lnwzaza1099";
	name[43] = "Banshee";
	name[44] = "Kid";
	name[45] = "Love";
	name[46] = "Evol";
	name[47] = "Trick";
	name[48] = "FFFzaza";
	name[49] = "Goblin";
	name[50] = "Radium";
	name[51] = "Utopia";
	name[52] = "Amity";
	name[53] = "Anya";
	name[54] = "Danika";
	name[55] = "Finny";
	name[56] = "Gene";
	name[57] = "Jeney";
	name[58] = "Music";
	name[59] = "Dot";
	name[60] = "Metrix";
	name[61] = "Star";
	name[62] = "Toy";
	name[63] = "Rain";
	name[64] = "TaeExzenfire";
	name[65] = "P'To";
	name[66] = "Brian";
	name[67] = "Benjamin";
	name[68] = "Tom";
	name[69] = "Jerry";
	name[70] = "DDDcc";
	name[71] = "Joker";
	name[72] = "Hayutya";
	name[73] = "Noname";
	name[74] = "Pravit";
	name[75] = "Chanaradee";
	name[76] = "Zero";
	name[77] = "Wolf";
	name[78] = "Tail";
	name[79] = "Saaaaaaad";
	name[80] = "Hacker";
	name[81] = "Eiei";
	name[82] = "wwwwww";
	name[83] = "Temple";
	name[84] = "Snow";
	name[85] = "Lava";
	name[86] = "Water";
	name[87] = "Winter";
	name[88] = "Zawarudo";
	name[89] = "Pile";
	name[90] = "Evans";
	name[91] = "Le";
	name[92] = "Natt";
	name[93] = "Plum";
	name[94] = "NSC";
	name[95] = "Intelligent";
	name[96] = "Found";
	name[97] = "YEAHH!!";
	name[98] = "I_c_e";
	name[99] = "GradeF";
	name[100] = "Film";

}


String charactername::callname(int random){

	return name[random];
}