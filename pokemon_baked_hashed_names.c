
#include "pokemon_dyntables.h"
btree *pokemon_hashed_names_btree;
size_t pokemon_hashed_names_btree_depth = 10;
void pokemon_hashed_names_init() {
  pokemon_hashed_names_btree =
  btree_alloc(2697832820072608251, // Lumineon, id 507, depth 1
    btree_alloc(1156414297958301231, // Emboar, id 559, depth 2
      btree_alloc(695452418869876742, // Charizard, id 6, depth 3
        btree_alloc(435186620805844424, // Bastiodon, id 456, depth 4
          btree_alloc(352130982728506397, // Arbok, id 29, depth 5
            btree_alloc(267716225850313037, // AggronMega Aggron, id 333, depth 6
              btree_alloc(235184407284938406, // Accelgor, id 678, depth 7
                btree_alloc(231666195532278852, // Abra, id 68, depth 8
                  btree_alloc(230927792645516798, // Abomasnow, id 510, depth 9
                    NULL,
                    btree_alloc(230927792645980671, // AbomasnowMega Abomasnow, id 511, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(232110123624121736, // Absol, id 392, depth 9
                    NULL,
                    btree_alloc(232110317499623817, // AbsolMega Absol, id 393, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(255243594251963545, // Aerodactyl, id 153, depth 8
                  btree_alloc(252004150826319598, // AegislashBlade Forme, id 750, depth 9
                    NULL,
                    btree_alloc(252004150826804975, // AegislashShield Forme, id 751, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(255243594252081306, // AerodactylMega Aerodactyl, id 154, depth 9
                    NULL,
                    btree_alloc(267716218669688140, // Aggron, id 332, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(310338003453430126, // AltariaMega Altaria, id 366, depth 7
                btree_alloc(304943673984280647, // AlakazamMega Alakazam, id 71, depth 8
                  btree_alloc(285903179579019469, // Aipom, id 205, depth 9
                    NULL,
                    btree_alloc(304943673974375494, // Alakazam, id 70, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(309019377259536015, // Alomomola, id 655, depth 9
                    NULL,
                    btree_alloc(310338003187431789, // Altaria, id 365, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(316848930428955276, // Amoonguss, id 652, depth 8
                  btree_alloc(312865775893441280, // Amaura, id 768, depth 9
                    NULL,
                    btree_alloc(313025866261949911, // Ambipom, id 471, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(317058159477665988, // AmpharosMega Ampharos, id 196, depth 9
                    btree_alloc(317058159467735235, // Ampharos, id 195, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(324687876406691195, // Anorith, id 379, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            ),
            btree_alloc(380187239656767233, // Aurorus, id 769, depth 6
              btree_alloc(355162773058546044, // Armaldo, id 380, depth 7
                btree_alloc(352343036156549747, // Archen, id 627, depth 8
                  btree_alloc(352271561065125952, // Arcanine, id 64, depth 9
                    NULL,
                    btree_alloc(352317322915205672, // Arceus, id 552, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(352343059939910260, // Archeops, id 628, depth 9
                    NULL,
                    btree_alloc(354002931731344566, // Ariados, id 182, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(357269598266161308, // Articuno, id 156, depth 8
                  btree_alloc(355865593889619697, // Aromatisse, id 753, depth 9
                    NULL,
                    btree_alloc(355875609412074826, // Aron, id 330, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(376072376037973582, // Audino, id 590, depth 9
                    NULL,
                    btree_alloc(376072383218600527, // AudinoMega Audino, id 591, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(431664330357298582, // Bagon, id 406, depth 7
                btree_alloc(415433383063646747, // Azelf, id 539, depth 8
                  btree_alloc(383048161824757525, // Avalugg, id 789, depth 9
                    NULL,
                    btree_alloc(399931604521388703, // Axew, id 671, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(420069706025759943, // Azumarill, id 199, depth 9
                    NULL,
                    btree_alloc(420126350004886850, // Azurill, id 322, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(433584348422074755, // BanetteMega Banette, id 387, depth 8
                  btree_alloc(433164690643079543, // Baltoy, id 375, depth 9
                    NULL,
                    btree_alloc(433584348156071298, // Banette, id 386, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(434706781640070515, // Barboach, id 371, depth 9
                    btree_alloc(434701476185639671, // Barbaracle, id 759, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(435009246210785890, // Basculin, id 610, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            )
          ),
          btree_alloc(562748505515351729, // Braviary, id 689, depth 5
            btree_alloc(493266086296506812, // Bidoof, id 444, depth 6
              btree_alloc(463077671332150939, // Beheeyem, id 667, depth 7
                btree_alloc(461230315070453026, // Beautifly, id 290, depth 8
                  btree_alloc(436834443633025191, // Bayleef, id 167, depth 9
                    NULL,
                    btree_alloc(461198178972301987, // Beartic, id 675, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(462204262432671762, // Beedrill, id 18, depth 9
                    NULL,
                    btree_alloc(462204262442577939, // BeedrillMega Beedrill, id 19, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(464314911477019723, // Bellsprout, id 75, depth 8
                  btree_alloc(464229959506823578, // Beldum, id 410, depth 9
                    NULL,
                    btree_alloc(464313369220210885, // Bellossom, id 197, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(465994119246920468, // Bergmite, id 788, depth 9
                    NULL,
                    btree_alloc(492538892975082941, // Bibarel, id 445, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(515939819820785943, // BlazikenMega Blaziken, id 279, depth 7
                btree_alloc(515869264957909003, // Blastoise, id 11, depth 8
                  btree_alloc(496003535384247030, // Binacle, id 758, depth 9
                    NULL,
                    btree_alloc(497523855131463342, // Bisharp, id 686, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(515869264958371852, // BlastoiseMega Blastoise, id 12, depth 9
                    NULL,
                    btree_alloc(515939819810866454, // Blaziken, id 278, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(542313773628986952, // Boldore, id 584, depth 8
                  btree_alloc(518182392389819653, // Blissey, id 261, depth 9
                    NULL,
                    btree_alloc(518195972790618693, // Blitzle, id 581, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(544934250628081327, // Bouffalant, id 687, depth 9
                    btree_alloc(543051770321144294, // Bonsly, id 486, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(562615264164681426, // Braixen, id 722, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            ),
            btree_alloc(641396624477823339, // Cacturne, id 363, depth 6
              btree_alloc(589138480666452992, // Bulbasaur, id 0, depth 7
                btree_alloc(566718673554823652, // Bronzor, id 484, depth 8
                  btree_alloc(563800805672532278, // Breloom, id 310, depth 9
                    NULL,
                    btree_alloc(566718671519128037, // Bronzong, id 485, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(586865399764190659, // Budew, id 451, depth 9
                    NULL,
                    btree_alloc(588529413811165649, // Buizel, id 465, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(591000794249782729, // Burmy, id 457, depth 8
                  btree_alloc(589749028492921306, // Buneary, id 474, depth 9
                    NULL,
                    btree_alloc(589846917810064087, // Bunnelby, id 727, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(591646523491529743, // Butterfree, id 15, depth 9
                    NULL,
                    btree_alloc(641325751065166186, // Cacnea, id 362, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(645748168470998363, // Carvanha, id 347, depth 7
                btree_alloc(645537115798479621, // Carbink, id 773, depth 8
                  btree_alloc(644126887221012833, // Camerupt, id 353, depth 9
                    NULL,
                    btree_alloc(644126887230949730, // CameruptMega Camerupt, id 354, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(645665769362398713, // Carnivine, id 505, depth 9
                    NULL,
                    btree_alloc(645705165425312370, // Carracosta, id 626, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(646151264560404493, // Caterpie, id 13, depth 8
                  btree_alloc(645839431682867491, // Cascoon, id 291, depth 9
                    NULL,
                    btree_alloc(646017957483000191, // Castform, id 383, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(695407287168563870, // Chandelure, id 670, depth 9
                    btree_alloc(675065593747266831, // Celebi, id 271, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(695413244584981625, // Chansey, id 121, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            )
          )
        ),
        btree_alloc(885131917193260726, // Deino, id 694, depth 4
          btree_alloc(751375740202151536, // Cofagrigus, id 624, depth 5
            btree_alloc(697710603550467463, // Chimecho, id 391, depth 6
              btree_alloc(696612577097322964, // Cherrim, id 468, depth 7
                btree_alloc(695453645205790724, // Charmander, id 4, depth 8
                  btree_alloc(695452418870347783, // CharizardMega Charizard X, id 7, depth 9
                    NULL,
                    btree_alloc(695452418870348808, // CharizardMega Charizard Y, id 8, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(695453702918032389, // Charmeleon, id 5, depth 9
                    NULL,
                    btree_alloc(695476132915061225, // Chatot, id 489, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(696622495606037198, // Chespin, id 718, depth 8
                  btree_alloc(696613662223317459, // Cherubi, id 467, depth 9
                    NULL,
                    btree_alloc(696621588579608272, // Chesnaught, id 720, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(697693368977844390, // Chikorita, id 166, depth 9
                    NULL,
                    btree_alloc(697709879830806963, // Chimchar, id 435, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(726740348370419451, // Clawitzer, id 763, depth 7
                btree_alloc(706857438572775034, // Cinccino, id 634, depth 8
                  btree_alloc(697720598911690936, // Chinchou, id 184, depth 9
                    NULL,
                    btree_alloc(697722241158100449, // Chingling, id 481, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(726635786758561169, // Clamperl, id 401, depth 9
                    NULL,
                    btree_alloc(726720649578669818, // Clauncher, id 762, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(727711746584660008, // Clefairy, id 40, depth 8
                  btree_alloc(726759706381521272, // Claydol, id 376, depth 9
                    NULL,
                    btree_alloc(727711640063413289, // Clefable, id 41, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(730814637015054434, // Cloyster, id 98, depth 9
                    btree_alloc(727713602331914427, // Cleffa, id 187, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(750220763564163771, // Cobalion, id 699, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            ),
            btree_alloc(777412801705951415, // Crobat, id 183, depth 6
              btree_alloc(755631279411290718, // Cottonee, id 606, depth 7
                btree_alloc(753795632943886930, // Conkeldurr, id 594, depth 8
                  btree_alloc(753409917016469966, // Combee, id 462, depth 9
                    NULL,
                    btree_alloc(753416476317068565, // Combusken, id 277, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(755007175296593269, // Corphish, id 373, depth 9
                    NULL,
                    btree_alloc(755042120654777584, // Corsola, id 240, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(773589754014854518, // Crawdaunt, id 374, depth 8
                  btree_alloc(773388384481608058, // Cradily, id 378, depth 9
                    NULL,
                    btree_alloc(773495375893156293, // Cranidos, id 453, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(774709744328674850, // Cresselia, id 546, depth 9
                    NULL,
                    btree_alloc(777404493149482487, // Croagunk, id 503, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(831805266974959785, // Cyndaquil, id 169, depth 7
                btree_alloc(780446442874284708, // Cryogonal, id 676, depth 8
                  btree_alloc(777428980015844525, // Croconaw, id 173, depth 9
                    NULL,
                    btree_alloc(779337565434413675, // Crustle, id 619, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(797092358318470818, // Cubchoo, id 674, depth 9
                    NULL,
                    btree_alloc(797223120354372720, // Cubone, id 112, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(856484286049187431, // DarmanitanStandard Mode, id 615, depth 8
                  btree_alloc(856469416044704293, // Darkrai, id 549, depth 9
                    NULL,
                    btree_alloc(856484286049155688, // DarmanitanZen Mode, id 616, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(883589287059685124, // Dedenne, id 772, depth 9
                    btree_alloc(856574547577144934, // Darumaka, id 614, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(884016881262161542, // Deerling, id 646, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            )
          ),
          btree_alloc(986553203837565401, // Drifblim, id 473, depth 5
            btree_alloc(914048076332430108, // DiancieMega Diancie, id 796, depth 6
              btree_alloc(886978532575264172, // DeoxysNormal Forme, id 428, depth 7
                btree_alloc(886018419962528467, // Delphox, id 723, depth 8
                  btree_alloc(885876466504129861, // Delcatty, id 325, depth 9
                    NULL,
                    btree_alloc(885940968495046899, // Delibird, id 243, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(886978525602660781, // DeoxysAttack Forme, id 429, depth 9
                    NULL,
                    btree_alloc(886978526922599854, // DeoxysDefense Forme, id 430, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(889193815888450097, // Dewott, id 561, depth 8
                  btree_alloc(886978535306463663, // DeoxysSpeed Forme, id 431, depth 9
                    NULL,
                    btree_alloc(889106056731790430, // Dewgong, id 94, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(914028119870189084, // Dialga, id 540, depth 9
                    NULL,
                    btree_alloc(914048076066449179, // Diancie, id 795, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(964682742751621371, // Donphan, id 251, depth 7
                btree_alloc(919611919200768143, // Ditto, id 143, depth 8
                  btree_alloc(915709276681226968, // Diggersby, id 728, depth 9
                    NULL,
                    btree_alloc(915762863561411639, // Diglett, id 55, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(961812681907189852, // Dodrio, id 92, depth 9
                    NULL,
                    btree_alloc(961846976024503387, // Doduo, id 91, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(984255434783753376, // Dragonair, id 160, depth 8
                  btree_alloc(966558819578742509, // Doublade, id 749, depth 9
                    NULL,
                    btree_alloc(984249854508178169, // Dragalge, id 761, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(984349478660378102, // Drapion, id 502, depth 9
                    btree_alloc(984255439349322913, // Dragonite, id 161, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(984392306852838559, // Dratini, id 159, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            ),
            btree_alloc(1012932213797011844, // Duskull, id 388, depth 6
              btree_alloc(1009556889664854072, // Dugtrio, id 56, depth 7
                btree_alloc(988479960692433000, // Drowzee, id 104, depth 8
                  btree_alloc(986557218388543960, // Drifloon, id 472, depth 9
                    NULL,
                    btree_alloc(986617609122912844, // Drilbur, id 588, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(990003023498173098, // Druddigon, id 682, depth 9
                    NULL,
                    btree_alloc(1008301219707786881, // Ducklett, id 641, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(1012533225920691893, // Durant, id 693, depth 8
                  btree_alloc(1011569723894045917, // Dunsparce, id 221, depth 9
                    NULL,
                    btree_alloc(1011856358174289535, // Duosion, id 639, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1012842998755922309, // Dusclops, id 389, depth 9
                    NULL,
                    btree_alloc(1012929479576998417, // Dusknoir, id 529, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(1140504031517411356, // Ekans, id 28, depth 7
                btree_alloc(1096734374355550872, // Eelektrik, id 664, depth 8
                  btree_alloc(1013026405889669412, // Dustox, id 292, depth 9
                    NULL,
                    btree_alloc(1024396583533751914, // Dwebble, id 618, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1096734374482979481, // Eelektross, id 665, depth 9
                    NULL,
                    btree_alloc(1099623768646889616, // Eevee, id 144, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(1149352315625818449, // Electrike, id 337, depth 8
                  btree_alloc(1149352062248624262, // Electabuzz, id 134, depth 9
                    NULL,
                    btree_alloc(1149352190430365189, // Electivire, id 517, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1149433432105739522, // Elekid, id 258, depth 9
                    btree_alloc(1149352318749903981, // Electrode, id 109, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(1150160352785175194, // Elgyem, id 666, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            )
          )
        )
      ),
      btree_alloc(1726212036657738420, // Heatmor, id 692, depth 3
        btree_alloc(1518995252002582630, // GengarMega Gengar, id 102, depth 4
          btree_alloc(1363098363132004066, // Floette, id 738, depth 5
            btree_alloc(1304526476512424987, // Fearow, id 27, depth 6
              btree_alloc(1207385891367004905, // Espurr, id 745, depth 7
                btree_alloc(1169324446252139783, // Entei, id 263, depth 8
                  btree_alloc(1160143996268608136, // Emolga, id 648, depth 9
                    NULL,
                    btree_alloc(1160467389130138040, // Empoleon, id 440, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1203413305148293770, // Escavalier, id 650, depth 9
                    NULL,
                    btree_alloc(1207213260011261139, // Espeon, id 211, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(1243093395942828143, // Exeggutor, id 111, depth 8
                  btree_alloc(1242449471555355213, // Excadrill, id 589, depth 9
                    NULL,
                    btree_alloc(1243093132099042414, // Exeggcute, id 110, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1246331403975900479, // Exploud, id 319, depth 9
                    NULL,
                    btree_alloc(1278076016295983194, // Farfetch'd, id 90, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(1339473703080531450, // Finneon, id 506, depth 7
                btree_alloc(1309259524038203566, // Feraligatr, id 174, depth 8
                  btree_alloc(1305506312633720189, // Feebas, id 381, depth 9
                    NULL,
                    btree_alloc(1308239194570098385, // Fennekin, id 721, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1309442953935101586, // Ferroseed, id 658, depth 9
                    NULL,
                    btree_alloc(1309442970473360019, // Ferrothorn, id 659, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(1359182682171495571, // Flareon, id 147, depth 8
                  btree_alloc(1359000858808143042, // Flaaffy, id 194, depth 9
                    NULL,
                    btree_alloc(1359009881570926305, // Flabébé, id 737, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1360360039169803993, // Fletchling, id 729, depth 9
                    btree_alloc(1360360037630491354, // Fletchinder, id 730, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(1363055605926832594, // Floatzel, id 466, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            ),
            btree_alloc(1484319072822926828, // Gabite, id 492, depth 6
              btree_alloc(1408286439224629901, // Frillish, id 653, depth 7
                btree_alloc(1386615466191472267, // Foongus, id 651, depth 8
                  btree_alloc(1363232241231819491, // Florges, id 739, depth 9
                    NULL,
                    btree_alloc(1366009789915363689, // Flygon, id 361, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1387525126775105756, // Forretress, id 220, depth 9
                    NULL,
                    btree_alloc(1406105008208709280, // Fraxure, id 672, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(1410096548783991314, // Froslass, id 530, depth 8
                  btree_alloc(1409903456379729620, // Froakie, id 724, depth 9
                    NULL,
                    btree_alloc(1409963686428591829, // Frogadier, id 725, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1434253346294957800, // Furfrou, id 744, depth 9
                    NULL,
                    btree_alloc(1434376787811863728, // Furret, id 176, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(1488877523655338478, // GarchompMega Garchomp, id 494, depth 7
                btree_alloc(1487343005400980113, // Galvantula, id 657, depth 8
                  btree_alloc(1487235735856194062, // Gallade, id 526, depth 9
                    NULL,
                    btree_alloc(1487235736122171919, // GalladeMega Gallade, id 527, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1488869428776416886, // Garbodor, id 630, depth 9
                    NULL,
                    btree_alloc(1488877523645417965, // Garchomp, id 493, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(1489350551729435747, // Gastly, id 99, depth 8
                  btree_alloc(1488887148705060145, // Gardevoir, id 305, depth 9
                    NULL,
                    btree_alloc(1488887148705519922, // GardevoirMega Gardevoir, id 306, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1518980773976104653, // Genesect, id 717, depth 9
                    btree_alloc(1489352787597673942, // Gastrodon, id 470, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(1518995244821967973, // Gengar, id 101, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            )
          ),
          btree_alloc(1598830527649196669, // Gothitelle, id 637, depth 5
            btree_alloc(1572338784340569611, // Gliscor, id 523, depth 6
              btree_alloc(1551329668156001825, // GiratinaOrigin Forme, id 545, depth 7
                btree_alloc(1548145211502914121, // Gigalith, id 585, depth 8
                  btree_alloc(1519260049848945744, // Geodude, id 80, depth 9
                    NULL,
                    btree_alloc(1546814077379866091, // Gible, id 491, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1551323998881093850, // Girafarig, id 218, depth 9
                    NULL,
                    btree_alloc(1551329668145397280, // GiratinaAltered Forme, id 544, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(1569952372529723789, // GlalieMega Glalie, id 397, depth 8
                  btree_alloc(1569854530411218442, // Glaceon, id 522, depth 9
                    NULL,
                    btree_alloc(1569952365349115276, // Glalie, id 396, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1569961649325777375, // Glameow, id 479, depth 9
                    NULL,
                    btree_alloc(1572209488367572190, // Gligar, id 222, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(1596486020718078034, // Golem, id 82, depth 7
                btree_alloc(1596449419755683887, // Golbat, id 47, depth 8
                  btree_alloc(1574034922797066289, // Gloom, id 49, depth 9
                    NULL,
                    btree_alloc(1595142628750740197, // Gogoat, id 741, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1596472216652892287, // Goldeen, id 127, depth 9
                    NULL,
                    btree_alloc(1596478533131035708, // Golduck, id 60, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(1597344931138651912, // Goodra, id 776, depth 8
                  btree_alloc(1596489091613758123, // Golett, id 683, depth 9
                    NULL,
                    btree_alloc(1596659548363947692, // Golurk, id 684, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1598217281940514195, // Gorebyss, id 403, depth 9
                    btree_alloc(1597444096090556166, // Goomy, id 774, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(1598830525221456507, // Gothita, id 635, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            ),
            btree_alloc(1620947520041907624, // GroudonPrimal Groudon, id 424, depth 6
              btree_alloc(1616822923934871778, // Granbull, id 226, depth 7
                btree_alloc(1599225837999097618, // GourgeistLarge Size, id 786, depth 8
                  btree_alloc(1598832880903796348, // Gothorita, id 636, depth 9
                    NULL,
                    btree_alloc(1599225837998819088, // GourgeistAverage Size, id 784, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1599225837999298321, // GourgeistSmall Size, id 785, depth 9
                    NULL,
                    btree_alloc(1599225837999320851, // GourgeistSuper Size, id 787, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(1619127014599734367, // Grimer, id 95, depth 8
                  btree_alloc(1616909669376089169, // Graveler, id 81, depth 9
                    NULL,
                    btree_alloc(1617982428183297750, // Greninja, id 726, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1620939827501048241, // Grotle, id 433, depth 9
                    NULL,
                    btree_alloc(1620947519705627047, // Groudon, id 423, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(1671525407583298700, // Gyarados, id 140, depth 7
                btree_alloc(1622601744218242405, // Grumpig, id 357, depth 8
                  btree_alloc(1620966513219899665, // Grovyle, id 273, depth 9
                    NULL,
                    btree_alloc(1620972031528094783, // Growlithe, id 63, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1643454135915923801, // Gulpin, id 345, depth 9
                    NULL,
                    btree_alloc(1645065675359516241, // Gurdurr, id 593, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(1699780849528028481, // Hariyama, id 321, depth 8
                  btree_alloc(1671525407593228429, // GyaradosMega Gyarados, id 141, depth 9
                    NULL,
                    btree_alloc(1699271263674625512, // Happiny, id 488, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1701257462751111939, // Hawlucha, id 771, depth 9
                    btree_alloc(1700700107953540196, // Haunter, id 100, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(1701577885090816673, // Haxorus, id 673, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            )
          )
        ),
        btree_alloc(2394773081532855600, // Kirlia, id 304, depth 4
          btree_alloc(1886658685662972009, // Hypno, id 105, depth 5
            btree_alloc(1807873721018553822, // Honchkrow, id 478, depth 6
              btree_alloc(1730955453794790966, // Herdier, id 566, depth 7
                btree_alloc(1729276306947506940, // Helioptile, id 764, depth 8
                  btree_alloc(1726213812367928862, // Heatran, id 542, depth 9
                    NULL,
                    btree_alloc(1729276242388902653, // Heliolisk, id 765, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1730921129055463655, // Heracross, id 231, depth 9
                    NULL,
                    btree_alloc(1730921129055930600, // HeracrossMega Heracross, id 232, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(1762867223949580403, // Hitmonchan, id 115, depth 8
                  btree_alloc(1761742562932105715, // Hippopotas, id 499, depth 9
                    NULL,
                    btree_alloc(1761742659707322868, // Hippowdon, id 500, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1762867228789474418, // Hitmonlee, id 114, depth 9
                    NULL,
                    btree_alloc(1762867233352804608, // Hitmontop, id 256, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(1808591845001071818, // Hoppip, id 202, depth 7
                btree_alloc(1808299354338118429, // HoopaHoopa Confined, id 797, depth 8
                  btree_alloc(1807893490780426988, // Honedge, id 748, depth 9
                    NULL,
                    btree_alloc(1808213140382558478, // Ho-oh, id 270, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1808299354338140958, // HoopaHoopa Unbound, id 798, depth 9
                    NULL,
                    btree_alloc(1808345079916612785, // Hoothoot, id 177, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(1810014471573207288, // HoundoomMega Houndoom, id 248, depth 8
                  btree_alloc(1809200587623289981, // Horsea, id 125, depth 9
                    NULL,
                    btree_alloc(1810014471563262199, // Houndoom, id 247, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(1854904675793573266, // Huntail, id 402, depth 9
                    btree_alloc(1810014474929212662, // Houndour, id 246, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(1883227206301279928, // Hydreigon, id 696, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            ),
            btree_alloc(2307846471740188805, // Jynx, id 133, depth 6
              btree_alloc(2150970900301931150, // Jellicent, id 654, depth 7
                btree_alloc(2008609390520398261, // Infernape, id 437, depth 8
                  btree_alloc(1954315906798927036, // Igglybuff, id 188, depth 9
                    NULL,
                    btree_alloc(1994896748880934231, // Illumise, id 343, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2010015154594185972, // Inkay, id 756, depth 9
                    NULL,
                    btree_alloc(2076716561364904961, // Ivysaur, id 1, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(2229141303807339666, // Jolteon, id 146, depth 8
                  btree_alloc(2180707270890127404, // Jigglypuff, id 44, depth 9
                    NULL,
                    btree_alloc(2183820464288696747, // Jirachi, id 427, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2229142824289802896, // Joltik, id 656, depth 9
                    NULL,
                    btree_alloc(2276242197950853324, // Jumpluff, id 204, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(2331090895425048700, // KangaskhanMega Kangaskhan, id 124, depth 7
                btree_alloc(2328134924982274117, // Kadabra, id 69, depth 8
                  btree_alloc(2327777833635574935, // Kabuto, id 151, depth 9
                    NULL,
                    btree_alloc(2327777842725654680, // Kabutops, id 152, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2330378118226368529, // Kakuna, id 17, depth 9
                    NULL,
                    btree_alloc(2331090895424948347, // Kangaskhan, id 123, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(2361716323309447881, // KeldeoOrdinary Forme, id 713, depth 8
                  btree_alloc(2332365302855791241, // Karrablast, id 649, depth 9
                    NULL,
                    btree_alloc(2359199143004345728, // Kecleon, id 384, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2393560959880093945, // Kingdra, id 249, depth 9
                    btree_alloc(2361716324691377866, // KeldeoResolute Forme, id 714, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(2393563951867414635, // Kingler, id 107, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            )
          ),
          btree_alloc(2543680085597469090, // LatiasMega Latias, id 418, depth 5
            btree_alloc(2518793328499850662, // KyogrePrimal Kyogre, id 422, depth 6
              btree_alloc(2460024516175308906, // Krabby, id 106, depth 7
                btree_alloc(2415618247945768596, // Klink, id 660, depth 8
                  btree_alloc(2413302998308593301, // Klang, id 661, depth 9
                    NULL,
                    btree_alloc(2414375857590429449, // Klefki, id 777, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2415618425096730262, // Klinklang, id 662, depth 9
                    NULL,
                    btree_alloc(2438090184748275829, // Koffing, id 117, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(2464174891498645092, // Krokorok, id 612, depth 8
                  btree_alloc(2462352178142622142, // Kricketot, id 446, depth 9
                    NULL,
                    btree_alloc(2462352178259212735, // Kricketune, id 447, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2464216100133831269, // Krookodile, id 613, depth 9
                    NULL,
                    btree_alloc(2518793319422763429, // Kyogre, id 421, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(2541896825521425092, // LandorusIncarnate Forme, id 708, depth 7
                btree_alloc(2520641364803179208, // KyuremWhite Kyurem, id 712, depth 8
                  btree_alloc(2520641352118078150, // Kyurem, id 710, depth 9
                    NULL,
                    btree_alloc(2520641353449257671, // KyuremBlack Kyurem, id 711, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2540600675326767435, // Lairon, id 331, depth 9
                    NULL,
                    btree_alloc(2541732127602937501, // Lampent, id 669, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(2542619649650536590, // Lapras, id 142, depth 8
                  btree_alloc(2541896825529457349, // LandorusTherian Forme, id 709, depth 9
                    NULL,
                    btree_alloc(2542070584060254393, // Lanturn, id 185, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2543244100296886537, // Larvitar, id 265, depth 9
                    btree_alloc(2543242508726357689, // Larvesta, id 697, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(2543680078416844193, // Latias, id 417, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            ),
            btree_alloc(2603870585875440181, // Lillipup, id 565, depth 6
              btree_alloc(2570458714856050867, // Ledyba, id 179, depth 7
                btree_alloc(2569388978168474121, // Leafeon, id 521, depth 8
                  btree_alloc(2543685632476974499, // Latios, id 419, depth 9
                    NULL,
                    btree_alloc(2543685639657613732, // LatiosMega Latios, id 420, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2569558759531632218, // Leavanny, id 602, depth 9
                    NULL,
                    btree_alloc(2570287126723242164, // Ledian, id 180, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(2601885822628769337, // Liepard, id 569, depth 8
                  btree_alloc(2601256938308961794, // Lickilicky, id 514, depth 9
                    NULL,
                    btree_alloc(2601257062603587700, // Lickitung, id 116, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2603794007438766457, // Lileep, id 377, depth 9
                    NULL,
                    btree_alloc(2603870442726619745, // Lilligant, id 609, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(2651977447146439132, // LopunnyMega Lopunny, id 476, depth 7
                btree_alloc(2606301877279680156, // Litwick, id 668, depth 8
                  btree_alloc(2604483477666500895, // Linoone, id 287, depth 9
                    NULL,
                    btree_alloc(2606182635320097503, // Litleo, id 735, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2650907747742304550, // Lombre, id 294, depth 9
                    NULL,
                    btree_alloc(2651977446880384475, // Lopunny, id 475, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(2694856695770875377, // Lucario, id 497, depth 8
                  btree_alloc(2652915863731587365, // Lotad, id 293, depth 9
                    NULL,
                    btree_alloc(2653242835485297982, // Loudred, id 318, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2695225730880387367, // Ludicolo, id 295, depth 9
                    btree_alloc(2694856696036891122, // LucarioMega Lucario, id 498, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(2696092333747409165, // Lugia, id 269, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            )
          )
        )
      )
    ),
    btree_alloc(4036691382685456516, // Scyther, id 132, depth 2
      btree_alloc(3385381848822793786, // Pansage, id 570, depth 3
        btree_alloc(2786741170151157923, // MewtwoMega Mewtwo X, id 163, depth 4
          btree_alloc(2752904582448772604, // Mantyke, id 508, depth 5
            btree_alloc(2750801291583199750, // Magmortar, id 518, depth 6
              btree_alloc(2749590792143884361, // Machoke, id 73, depth 7
                btree_alloc(2701014421178600897, // Luxio, id 449, depth 8
                  btree_alloc(2698038863223223665, // Lunatone, id 369, depth 9
                    NULL,
                    btree_alloc(2700380348972923285, // Luvdisc, id 405, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2701105637065607618, // Luxray, id 450, depth 9
                    NULL,
                    btree_alloc(2749585273456467018, // Machamp, id 74, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(2750688616700467437, // Magcargo, id 237, depth 8
                  btree_alloc(2749590862889311304, // Machop, id 72, depth 9
                    NULL,
                    btree_alloc(2750687157953974531, // Magby, id 259, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2750756608516887691, // Magikarp, id 139, depth 9
                    NULL,
                    btree_alloc(2750795726605568135, // Magmar, id 135, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(2752559616065589772, // Mamoswine, id 524, depth 7
                btree_alloc(2750808150876656129, // Magnezone, id 513, depth 8
                  btree_alloc(2750807956719764568, // Magnemite, id 88, depth 9
                    NULL,
                    btree_alloc(2750808062713239641, // Magneton, id 89, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2752040904895036736, // Makuhita, id 320, depth 9
                    NULL,
                    btree_alloc(2752117749644908277, // Malamar, id 757, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(2752735323112503634, // Manectric, id 338, depth 8
                  btree_alloc(2752697462153697828, // Manaphy, id 548, depth 9
                    NULL,
                    btree_alloc(2752726729535652531, // Mandibuzz, id 691, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2752800448446992445, // Mankey, id 61, depth 9
                    btree_alloc(2752735323112950099, // ManectricMega Manectric, id 339, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(2752898279031322868, // Mantine, id 244, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            ),
            btree_alloc(2781906673876064424, // Meganium, id 168, depth 6
              btree_alloc(2754316819538308404, // Masquerain, id 308, depth 7
                btree_alloc(2753938443042474182, // Marill, id 198, depth 8
                  btree_alloc(2753849310719112809, // Maractus, id 617, depth 9
                    NULL,
                    btree_alloc(2753892879178812609, // Mareep, id 193, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2754006919717003377, // Marowak, id 113, depth 9
                    NULL,
                    btree_alloc(2754044096168090905, // Marshtomp, id 281, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(2781120352071853391, // Medicham, id 335, depth 8
                  btree_alloc(2755384379416291656, // Mawile, id 328, depth 9
                    NULL,
                    btree_alloc(2755384386596917577, // MawileMega Mawile, id 329, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2781120352081748304, // MedichamMega Medicham, id 336, depth 9
                    NULL,
                    btree_alloc(2781127121159479630, // Meditite, id 334, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(2785539425113649690, // Mesprit, id 538, depth 7
                btree_alloc(2784458125967608555, // MeowsticFemale, id 747, depth 8
                  btree_alloc(2783499263100469963, // MeloettaAria Forme, id 715, depth 9
                    NULL,
                    btree_alloc(2783499263111509708, // MeloettaPirouette Forme, id 716, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2784458125972711146, // MeowsticMale, id 746, depth 9
                    NULL,
                    btree_alloc(2784458341403952185, // Meowth, id 57, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(2785666334789012891, // Metang, id 411, depth 8
                  btree_alloc(2785663727945102748, // Metagross, id 412, depth 9
                    NULL,
                    btree_alloc(2785663727945580957, // MetagrossMega Metagross, id 413, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2786517590010309797, // Mew, id 165, depth 9
                    btree_alloc(2785667247949201422, // Metapod, id 14, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(2786741162970472610, // Mewtwo, id 162, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            )
          ),
          btree_alloc(3023257441783627810, // Nidoran♀, id 34, depth 5
            btree_alloc(2861643874731821214, // Moltres, id 158, depth 6
              btree_alloc(2814785587454150916, // Miltank, id 260, depth 7
                btree_alloc(2812703911761718953, // Mienshao, id 681, depth 8
                  btree_alloc(2786741170151158948, // MewtwoMega Mewtwo Y, id 164, depth 9
                    NULL,
                    btree_alloc(2812698864589543080, // Mienfoo, id 680, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2813218707704078621, // Mightyena, id 285, depth 9
                    NULL,
                    btree_alloc(2814739490278817150, // Milotic, id 382, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(2815379660196013397, // Minun, id 341, depth 8
                  btree_alloc(2814913672591973863, // Mime Jr., id 487, depth 9
                    NULL,
                    btree_alloc(2815182631221980793, // Minccino, id 633, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2816645266938775767, // Misdreavus, id 215, depth 9
                    NULL,
                    btree_alloc(2816734959055975901, // Mismagius, id 477, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(2908887993897102831, // Munchlax, id 495, depth 7
                btree_alloc(2881520775709943939, // Mr. Mime, id 131, depth 8
                  btree_alloc(2862067362051468724, // Monferno, id 436, depth 9
                    NULL,
                    btree_alloc(2863825537413819853, // Mothim, id 461, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(2906082061120757016, // Mudkip, id 280, depth 9
                    NULL,
                    btree_alloc(2907984885060058208, // Muk, id 96, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(2910384907872873025, // Musharna, id 577, depth 8
                  btree_alloc(2909002864938225216, // Munna, id 576, depth 9
                    NULL,
                    btree_alloc(2910134539246191829, // Murkrow, id 213, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(3023254782440896551, // Nidoking, id 39, depth 9
                    btree_alloc(2965472977875930303, // Natu, id 191, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(3023257334144129060, // Nidoqueen, id 36, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            ),
            btree_alloc(3123286060376839465, // Nuzleaf, id 297, depth 6
              btree_alloc(3026089481859389755, // Ninjask, id 315, depth 7
                btree_alloc(3023257559632204838, // Nidorino, id 38, depth 8
                  btree_alloc(3023257441783627813, // Nidoran♂, id 37, depth 9
                    NULL,
                    btree_alloc(3023257559350029347, // Nidorina, id 35, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(3026014276206463290, // Nincada, id 314, depth 9
                    NULL,
                    btree_alloc(3026043198684124203, // Ninetales, id 43, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(3071625224214155031, // Noivern, id 791, depth 8
                  btree_alloc(3069872593902475442, // Noctowl, id 178, depth 9
                    NULL,
                    btree_alloc(3071409431074059030, // Noibat, id 790, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(3074339326061706563, // Nosepass, id 323, depth 9
                    NULL,
                    btree_alloc(3119454137647058272, // Numel, id 352, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(3313185144019839536, // Oshawott, id 560, depth 7
                btree_alloc(3264449124713946261, // Omanyte, id 149, depth 8
                  btree_alloc(3191799124014716146, // Octillery, id 242, depth 9
                    NULL,
                    btree_alloc(3194983125468145712, // Oddish, id 48, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(3264500426031649942, // Omastar, id 150, depth 9
                    NULL,
                    btree_alloc(3274668298767115367, // Onix, id 103, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(3384774669153432148, // Palpitoad, id 596, depth 8
                  btree_alloc(3382086075055536592, // Pachirisu, id 464, depth 9
                    NULL,
                    btree_alloc(3384720824786626077, // Palkia, id 541, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(3385259033130810087, // Pangoro, id 743, depth 9
                    btree_alloc(3385213159619861222, // Pancham, id 742, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(3385355481458357822, // Panpour, id 574, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            )
          )
        ),
        btree_alloc(3766484829950404835, // Qwilfish, id 227, depth 4
          btree_alloc(3473305365608032596, // Plusle, id 340, depth 5
            btree_alloc(3444559460500079802, // Pichu, id 186, depth 6
              btree_alloc(3415936849794822446, // Pelipper, id 302, depth 7
                btree_alloc(3386352985836589108, // Parasect, id 52, depth 8
                  btree_alloc(3385383354611974716, // Pansear, id 572, depth 9
                    NULL,
                    btree_alloc(3386352910334493747, // Paras, id 51, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(3387106572784926259, // Patrat, id 563, depth 9
                    NULL,
                    btree_alloc(3387934255166727853, // Pawniard, id 685, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(3436235085133933818, // Phanpy, id 250, depth 8
                  btree_alloc(3417776217989447738, // Persian, id 58, depth 9
                    NULL,
                    btree_alloc(3418248826276959840, // Petilil, id 608, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(3436236620632161034, // Phantump, id 778, depth 9
                    NULL,
                    btree_alloc(3438558371995689507, // Phione, id 547, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(3445776096255207982, // Pignite, id 558, depth 7
                btree_alloc(3444831841143888917, // Pidgeotto, id 21, depth 8
                  btree_alloc(3444831840729585686, // Pidgeot, id 22, depth 9
                    NULL,
                    btree_alloc(3444831840995598359, // PidgeotMega Pidgeot, id 23, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(3444831976778482708, // Pidgey, id 20, depth 9
                    NULL,
                    btree_alloc(3444924118342179394, // Pidove, id 578, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(3447701692058719451, // Pineco, id 219, depth 8
                  btree_alloc(3446791131491071006, // Pikachu, id 30, depth 9
                    NULL,
                    btree_alloc(3447236860612008175, // Piloswine, id 239, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(3447854083254212745, // PinsirMega Pinsir, id 137, depth 9
                    btree_alloc(3447854076073564296, // Pinsir, id 136, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(3448362243188925878, // Piplup, id 438, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            ),
            btree_alloc(3518241048378254864, // Probopass, id 528, depth 6
              btree_alloc(3494823281578084636, // Poochyena, id 284, depth 7
                btree_alloc(3494025629710647362, // Poliwhirl, id 66, depth 8
                  btree_alloc(3494024539939955913, // Politoed, id 201, depth 9
                    NULL,
                    btree_alloc(3494025525397537857, // Poliwag, id 65, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(3494025772327215171, // Poliwrath, id 67, depth 9
                    NULL,
                    btree_alloc(3494774129550018643, // Ponyta, id 83, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(3495926017438601741, // Porygon-Z, id 525, depth 8
                  btree_alloc(3495926016914562300, // Porygon2, id 252, depth 9
                    NULL,
                    btree_alloc(3495926016914563220, // Porygon, id 148, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(3516619447006150718, // Primeape, id 62, depth 9
                    NULL,
                    btree_alloc(3516634686880994743, // Prinplup, id 439, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(3542032843557133578, // Pupitar, id 266, depth 7
                btree_alloc(3541236620972407566, // PumpkabooLarge Size, id 782, depth 8
                  btree_alloc(3528965355803462715, // Psyduck, id 59, depth 9
                    NULL,
                    btree_alloc(3541236620972129036, // PumpkabooAverage Size, id 780, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(3541236620972608269, // PumpkabooSmall Size, id 781, depth 9
                    NULL,
                    btree_alloc(3541236620972630799, // PumpkabooSuper Size, id 783, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(3573902677293652704, // Pyroar, id 736, depth 8
                  btree_alloc(3542704689204664888, // Purrloin, id 568, depth 9
                    NULL,
                    btree_alloc(3542734804161913312, // Purugly, id 480, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(3750865803764135082, // Quilava, id 170, depth 9
                    btree_alloc(3748505543266787538, // Quagsire, id 210, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(3750869860934061775, // Quilladin, id 719, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            )
          ),
          btree_alloc(3918064509411855891, // Rotom, id 531, depth 5
            btree_alloc(3836156626612282782, // Regirock, id 414, depth 6
              btree_alloc(3808675733949161497, // Raticate, id 25, depth 7
                btree_alloc(3806486218424113455, // Ralts, id 303, depth 8
                  btree_alloc(3805432445713992735, // Raichu, id 31, depth 9
                    NULL,
                    btree_alloc(3805520913957497094, // Raikou, id 262, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(3806725706700643782, // Rampardos, id 454, depth 9
                    NULL,
                    btree_alloc(3807519298802586708, // Rapidash, id 84, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(3810214608518338986, // RayquazaMega Rayquaza, id 426, depth 8
                  btree_alloc(3808793034662321176, // Rattata, id 24, depth 9
                    NULL,
                    btree_alloc(3810214608508388777, // Rayquaza, id 425, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(3836150527046470047, // Regice, id 415, depth 9
                    NULL,
                    btree_alloc(3836152176537621023, // Regigigas, id 543, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(3864733439590863992, // Rhydon, id 120, depth 7
                btree_alloc(3837955939512656113, // Remoraid, id 241, depth 8
                  btree_alloc(3836157097773683104, // Registeel, id 416, depth 9
                    NULL,
                    btree_alloc(3837596515527944596, // Relicanth, id 404, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(3839612881919417026, // Reshiram, id 706, depth 9
                    NULL,
                    btree_alloc(3840255351782574720, // Reuniclus, id 640, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(3869737838780919280, // Riolu, id 496, depth 8
                  btree_alloc(3864776351589443703, // Rhyhorn, id 119, depth 9
                    NULL,
                    btree_alloc(3864858073211863555, // Rhyperior, id 515, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(3917667923614840152, // Roselia, id 344, depth 9
                    btree_alloc(3914216158272898631, // Roggenrola, id 583, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(3917670188113441220, // Roserade, id 452, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            ),
            btree_alloc(4017721982807407203, // Sandile, id 611, depth 6
              btree_alloc(3960770555541238448, // Rufflet, id 688, depth 7
                btree_alloc(3918064629714237972, // RotomHeat Rotom, id 532, depth 8
                  btree_alloc(3918064598398464535, // RotomFan Rotom, id 535, depth 9
                    NULL,
                    btree_alloc(3918064607684199958, // RotomFrost Rotom, id 534, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(3918064709051566616, // RotomMow Rotom, id 536, depth 9
                    NULL,
                    btree_alloc(3918064848290506261, // RotomWash Rotom, id 533, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(4017112921894968728, // Salamence, id 408, depth 8
                  btree_alloc(4014335784014894406, // Sableye, id 326, depth 9
                    NULL,
                    btree_alloc(4014335784280899911, // SableyeMega Sableye, id 327, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4017112921895401881, // SalamenceMega Salamence, id 409, depth 9
                    NULL,
                    btree_alloc(4017618491903717938, // Samurott, id 562, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(4030869196403300626, // Sceptile, id 274, depth 7
                btree_alloc(4020396083719804503, // Sawk, id 599, depth 8
                  btree_alloc(4017725898412577824, // Sandshrew, id 32, depth 9
                    NULL,
                    btree_alloc(4017725948205354017, // Sandslash, id 33, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4020482878783593095, // Sawsbuck, id 647, depth 9
                    NULL,
                    btree_alloc(4029755155076046556, // Scatterbug, id 732, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(4032131290997680357, // ScizorMega Scizor, id 229, depth 8
                  btree_alloc(4030869196413229331, // SceptileMega Sceptile, id 275, depth 9
                    NULL,
                    btree_alloc(4032131283817026788, // Scizor, id 228, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4034462841907462765, // Scrafty, id 621, depth 9
                    btree_alloc(4033714164372931165, // Scolipede, id 605, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(4034463047613393516, // Scraggy, id 620, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            )
          )
        )
      ),
      btree_alloc(4259957031562781774, // Tentacool, id 78, depth 3
        btree_alloc(4116602799856516329, // Sneasel, id 233, depth 4
          btree_alloc(4074396802532771046, // Shuckle, id 230, depth 5
            btree_alloc(4068775197148910940, // Sharpedo, id 348, depth 6
              btree_alloc(4047672613164928597, // Seismitoad, id 597, depth 7
                btree_alloc(4045280873814260111, // Sealeo, id 399, depth 8
                  btree_alloc(4045200134236439678, // Seadra, id 126, depth 9
                    NULL,
                    btree_alloc(4045271738402990208, // Seaking, id 128, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4046356054634458408, // Seedot, id 296, depth 9
                    NULL,
                    btree_alloc(4046435501203572829, // Seel, id 93, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(4050306096104139307, // Servine, id 555, depth 8
                  btree_alloc(4049131288309986479, // Sentret, id 175, depth 9
                    NULL,
                    btree_alloc(4050240302085408300, // Serperior, id 556, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4051326331128807792, // Seviper, id 368, depth 9
                    NULL,
                    btree_alloc(4051525069280078424, // Sewaddle, id 600, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(4069866159157315681, // Shellder, id 97, depth 7
                btree_alloc(4068849051109581351, // ShayminSky Forme, id 551, depth 8
                  btree_alloc(4068775197158836573, // SharpedoMega Sharpedo, id 349, depth 9
                    NULL,
                    btree_alloc(4068849050960727590, // ShayminLand Forme, id 550, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4069779427099278652, // Shedinja, id 316, depth 9
                    NULL,
                    btree_alloc(4069864341725464983, // Shelgon, id 407, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(4070948016088317383, // Shieldon, id 455, depth 8
                  btree_alloc(4069866328039346645, // Shellos, id 469, depth 9
                    NULL,
                    btree_alloc(4069866578369315493, // Shelmet, id 677, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4071049112108175808, // Shinx, id 448, depth 9
                    btree_alloc(4070962112104355114, // Shiftry, id 298, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(4073659319950168373, // Shroomish, id 309, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            ),
            btree_alloc(4096976890044668664, // Skrelp, id 760, depth 6
              btree_alloc(4079959089086319165, // Simisear, id 573, depth 7
                btree_alloc(4079604179601114401, // Silcoon, id 289, depth 8
                  btree_alloc(4074537939657481601, // Shuppet, id 385, depth 9
                    NULL,
                    btree_alloc(4078221366811109998, // Sigilyph, id 622, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4079958056747296319, // Simipour, id 575, depth 9
                    NULL,
                    btree_alloc(4079959033316349499, // Simisage, id 571, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(4094491838586608843, // Skiploom, id 203, depth 8
                  btree_alloc(4092199997220148469, // Skarmory, id 245, depth 9
                    NULL,
                    btree_alloc(4094360119592853220, // Skiddo, id 740, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4094537996449830212, // Skitty, id 324, depth 9
                    NULL,
                    btree_alloc(4096252090095422965, // Skorupi, id 501, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(4104106754193190999, // SlowbroMega Slowbro, id 87, depth 7
                btree_alloc(4099934490190741815, // Slakoth, id 311, depth 8
                  btree_alloc(4097943877385736675, // Skuntank, id 483, depth 9
                    NULL,
                    btree_alloc(4099932021175377209, // Slaking, id 313, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4102202063941194503, // Sliggoo, id 775, depth 9
                    NULL,
                    btree_alloc(4104106753927149654, // Slowbro, id 86, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(4105674724528093420, // Slugma, id 236, depth 8
                  btree_alloc(4104110191751740630, // Slowking, id 214, depth 9
                    NULL,
                    btree_alloc(4104112261831431253, // Slowpoke, id 85, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4108793820800646398, // Smeargle, id 254, depth 9
                    btree_alloc(4105794037354033907, // Slurpuff, id 755, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(4111829927851303169, // Smoochum, id 257, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            )
          ),
          btree_alloc(4166561271161993783, // Stoutland, id 567, depth 5
            btree_alloc(4133510087026854246, // Spinda, id 358, depth 6
              btree_alloc(4126585888804649598, // Solosis, id 638, depth 7
                btree_alloc(4119677902168892811, // Snorunt, id 395, depth 8
                  btree_alloc(4117986870987955754, // Snivy, id 554, depth 9
                    NULL,
                    btree_alloc(4119674142865798299, // Snorlax, id 155, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4119714448167533053, // Snover, id 509, depth 9
                    NULL,
                    btree_alloc(4121234327902384353, // Snubbull, id 225, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(4132454418883516125, // Spewpa, id 733, depth 8
                  btree_alloc(4126616343622116722, // Solrock, id 370, depth 9
                    NULL,
                    btree_alloc(4132219779706147866, // Spearow, id 26, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4133123448036725134, // Spheal, id 398, depth 9
                    NULL,
                    btree_alloc(4133509147422787765, // Spinarak, id 181, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(4162472758612373947, // Staraptor, id 443, depth 7
                btree_alloc(4136066118277727984, // Spritzee, id 752, depth 8
                  btree_alloc(4133555203825255914, // Spiritomb, id 490, depth 9
                    NULL,
                    btree_alloc(4135195891209209188, // Spoink, id 356, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4144741475850946569, // Squirtle, id 9, depth 9
                    NULL,
                    btree_alloc(4162437383769661693, // Stantler, id 253, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(4162477407903677570, // Starmie, id 130, depth 8
                  btree_alloc(4162472840490295738, // Staravia, id 442, depth 9
                    NULL,
                    btree_alloc(4162477243556612537, // Starly, id 441, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4163494604684400863, // Steelix, id 223, depth 9
                    btree_alloc(4162482342125038721, // Staryu, id 129, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(4163494604950431968, // SteelixMega Steelix, id 224, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            ),
            btree_alloc(4185850825239382299, // SwampertMega Swampert, id 283, depth 6
              btree_alloc(4173967705294821582, // Sunkern, id 206, depth 7
                btree_alloc(4171125569938599112, // Sudowoodo, id 200, depth 8
                  btree_alloc(4168215950014470823, // Stunfisk, id 679, depth 9
                    NULL,
                    btree_alloc(4168218158138443234, // Stunky, id 482, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4172442258681008392, // Suicune, id 264, depth 9
                    NULL,
                    btree_alloc(4173916883433581775, // Sunflora, id 207, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(4185752980919274073, // Swadloon, id 601, depth 8
                  btree_alloc(4175212479226817843, // Surskit, id 307, depth 9
                    NULL,
                    btree_alloc(4185731637830491500, // Swablu, id 364, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4185839927309751642, // Swalot, id 346, depth 9
                    NULL,
                    btree_alloc(4185850825229426970, // Swampert, id 282, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(4204741518241252098, // Sylveon, id 770, depth 7
                btree_alloc(4188177128708394222, // Swinub, id 238, depth 8
                  btree_alloc(4185860674222196354, // Swanna, id 642, depth 9
                    NULL,
                    btree_alloc(4186995507585529132, // Swellow, id 300, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4188216519761545970, // Swirlix, id 754, depth 9
                    NULL,
                    btree_alloc(4189915545719809611, // Swoobat, id 587, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(4228585047226261626, // Tangela, id 122, depth 8
                  btree_alloc(4227195398090088747, // Taillow, id 299, depth 9
                    NULL,
                    btree_alloc(4228095811072676571, // Talonflame, id 731, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4230731397056814218, // Tauros, id 138, depth 9
                    btree_alloc(4228590261029034500, // Tangrowth, id 516, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(4256897010615035114, // Teddiursa, id 234, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            )
          )
        ),
        btree_alloc(4709678562890482217, // Victini, id 553, depth 4
          btree_alloc(4386060463441844656, // Turtwig, id 432, depth 5
            btree_alloc(4339020745710033172, // Torchic, id 276, depth 6
              btree_alloc(4285344509938273985, // ThundurusTherian Forme, id 705, depth 7
                btree_alloc(4261092554423414460, // Terrakion, id 700, depth 8
                  btree_alloc(4259957033311406159, // Tentacruel, id 79, depth 9
                    NULL,
                    btree_alloc(4260419949592440365, // Tepig, id 557, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4284488865885693526, // Throh, id 598, depth 9
                    NULL,
                    btree_alloc(4285344509937989312, // ThundurusIncarnate Forme, id 704, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(4335862081460294151, // Togekiss, id 519, depth 8
                  btree_alloc(4290717621877821008, // Timburr, id 592, depth 9
                    NULL,
                    btree_alloc(4292354124137202289, // Tirtouga, id 625, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4335864054330531005, // Togepi, id 189, depth 9
                    NULL,
                    btree_alloc(4335865642837439678, // Togetic, id 190, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(4340818416397586936, // Toxicroak, id 504, depth 7
                btree_alloc(4339135730825759423, // TornadusTherian Forme, id 703, depth 8
                  btree_alloc(4339109101305051491, // Torkoal, id 355, depth 9
                    NULL,
                    btree_alloc(4339135730817727166, // TornadusIncarnate Forme, id 702, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4339201789805463986, // Torterra, id 434, depth 9
                    NULL,
                    btree_alloc(4339726116345117868, // Totodile, id 172, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(4358706354321642768, // Treecko, id 272, depth 8
                  btree_alloc(4357651623533920835, // Tranquill, id 579, depth 9
                    NULL,
                    btree_alloc(4357669766380917095, // Trapinch, id 359, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4361718787614761350, // Tropius, id 390, depth 9
                    btree_alloc(4358889278345570059, // Trevenant, id 779, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(4363301121875190389, // Trubbish, id 629, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            ),
            btree_alloc(4573550858803876075, // Ursaring, id 235, depth 6
              btree_alloc(4417087991686413055, // Tyrantrum, id 767, depth 7
                btree_alloc(4416583689208103083, // Typhlosion, id 171, depth 8
                  btree_alloc(4415802895149654611, // Tympole, id 595, depth 9
                    NULL,
                    btree_alloc(4415930679891517079, // Tynamo, id 663, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4417087830749339915, // Tyranitar, id 267, depth 9
                    NULL,
                    btree_alloc(4417087830749827340, // TyranitarMega Tyranitar, id 268, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(4529768290815287508, // Umbreon, id 212, depth 8
                  btree_alloc(4417235181465638143, // Tyrogue, id 255, depth 9
                    NULL,
                    btree_alloc(4417302209491525374, // Tyrunt, id 766, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4538602611586873924, // Unfezant, id 580, depth 9
                    NULL,
                    btree_alloc(4541393504087227608, // Unown, id 216, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(4681510218642755163, // Venipede, id 603, depth 7
                btree_alloc(4650274290349931139, // Vanillite, id 643, depth 8
                  btree_alloc(4617546015970988569, // Uxie, id 537, depth 9
                    NULL,
                    btree_alloc(4650274290332015236, // Vanillish, id 644, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4650274296960899717, // Vanilluxe, id 645, depth 9
                    NULL,
                    btree_alloc(4650919255049751697, // Vaporeon, id 145, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(4681639896358877186, // Venusaur, id 2, depth 8
                  btree_alloc(4681573452597494838, // Venomoth, id 54, depth 9
                    NULL,
                    btree_alloc(4681573643448902709, // Venonat, id 53, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4683028646232375759, // Vespiquen, id 463, depth 9
                    btree_alloc(4681639896368838659, // VenusaurMega Venusaur, id 3, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(4709364871685801320, // Vibrava, id 360, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            )
          ),
          btree_alloc(4921530023510877229, // Wigglytuff, id 45, depth 5
            btree_alloc(4859693202949645662, // Wailmer, id 350, depth 6
              btree_alloc(4758938527315391830, // Volbeat, id 342, depth 7
                btree_alloc(4712123516913093682, // Vileplume, id 50, depth 8
                  btree_alloc(4709681998985771085, // Victreebel, id 77, depth 9
                    NULL,
                    btree_alloc(4710785428571409720, // Vigoroth, id 312, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4713905529449168573, // Virizion, id 701, depth 9
                    NULL,
                    btree_alloc(4715056850850306782, // Vivillon, id 734, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(4759135539721689196, // Voltorb, id 108, depth 8
                  btree_alloc(4758947837182027551, // Volcanion, id 799, depth 9
                    NULL,
                    btree_alloc(4758947899190464186, // Volcarona, id 698, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4805895742819886770, // Vullaby, id 690, depth 9
                    NULL,
                    btree_alloc(4805942071822539818, // Vulpix, id 42, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(4889684721139186704, // Weedle, id 16, depth 7
                btree_alloc(4862382750555090954, // Wartortle, id 10, depth 8
                  btree_alloc(4859694179780718943, // Wailord, id 351, depth 9
                    NULL,
                    btree_alloc(4860621977743489424, // Walrein, id 400, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4862776243987201588, // Watchog, id 564, depth 9
                    NULL,
                    btree_alloc(4888719610406198784, // Weavile, id 512, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(4914366628363197023, // Whimsicott, id 607, depth 8
                  btree_alloc(4889812201241583692, // Weepinbell, id 76, depth 9
                    NULL,
                    btree_alloc(4889919317869296758, // Weezing, id 118, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4914424440280298868, // Whiscash, id 372, depth 9
                    btree_alloc(4914417415202161244, // Whirlipede, id 604, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(4914428700626283837, // Whismur, id 317, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            ),
            btree_alloc(5282810148223058128, // Yanma, id 208, depth 6
              btree_alloc(4971622566213039563, // WormadamSandy Cloak, id 459, depth 7
                btree_alloc(4970637351530483274, // Woobat, id 586, depth 8
                  btree_alloc(4923557853101480237, // Wingull, id 301, depth 9
                    NULL,
                    btree_alloc(4966885381587409113, // Wobbuffet, id 217, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(4970788868641762513, // Wooper, id 209, depth 9
                    NULL,
                    btree_alloc(4971622566211096010, // WormadamPlant Cloak, id 458, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(5048431484901328266, // Wynaut, id 394, depth 8
                  btree_alloc(4971622566214240716, // WormadamTrash Cloak, id 460, depth 9
                    NULL,
                    btree_alloc(5018480307386233120, // Wurmple, id 288, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(5104381230947068696, // Xerneas, id 792, depth 9
                    btree_alloc(5073798170525136064, // Xatu, id 192, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(5282399706118084207, // Yamask, id 623, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              ),
              btree_alloc(5524068793331594947, // Zekrom, id 707, depth 7
                btree_alloc(5493584183977731439, // Zangoose, id 367, depth 8
                  btree_alloc(5282811838494540296, // Yanmega, id 520, depth 9
                    NULL,
                    btree_alloc(5444184973406990105, // Yveltal, id 793, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(5494130513796036765, // Zapdos, id 157, depth 9
                    NULL,
                    btree_alloc(5521478696304586310, // Zebstrika, id 582, depth 10
                      NULL,
                      NULL
                    )
                  )
                ),
                btree_alloc(5604205755627617911, // Zorua, id 631, depth 8
                  btree_alloc(5554226466718011678, // Zigzagoon, id 286, depth 9
                    NULL,
                    btree_alloc(5604141757682741880, // Zoroark, id 632, depth 10
                      NULL,
                      NULL
                    )
                  ),
                  btree_alloc(5662791007529494199, // Zweilous, id 695, depth 9
                    btree_alloc(5646223410669109294, // Zubat, id 46, depth 10
                      NULL,
                      NULL
                    ),
                    btree_alloc(5678903165256258330, // Zygarde50% Forme, id 794, depth 10
                      NULL,
                      NULL
                    )
                  )
                )
              )
            )
          )
        )
      )
    )
  );
}

