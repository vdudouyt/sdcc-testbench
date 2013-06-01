                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 2.8.0 #5108 (Mar 19 2008) (UNIX)
                              4 ; This file was generated Thu Mar 20 10:06:10 2008
                              5 ;--------------------------------------------------------
                              6 	.module sdcc_mullong
                              7 	.optsdcc -mhc08
                              8 	
                              9 	.area HOME (CODE)
                             10 	.area GSINIT0 (CODE)
                             11 	.area GSINIT (CODE)
                             12 	.area GSFINAL (CODE)
                             13 	.area CSEG (CODE)
                             14 	.area XINIT
                             15 	.area CONST   (CODE)
                             16 	.area DSEG
                             17 	.area OSEG    (OVR)
                             18 	.area BSEG
                             19 	.area XSEG
                             20 	.area XISEG
                             21 ;--------------------------------------------------------
                             22 ; Public variables in this module
                             23 ;--------------------------------------------------------
                             24 	.globl __mullong_PARM_2
                             25 	.globl __mullong_PARM_1
                             26 	.globl __mullong
                             27 ;--------------------------------------------------------
                             28 ;  ram data
                             29 ;--------------------------------------------------------
                             30 	.area DSEG
                             31 ;--------------------------------------------------------
                             32 ; overlayable items in  ram 
                             33 ;--------------------------------------------------------
                             34 	.area	OSEG    (OVR)
   0082                      35 __mullong_sloc0_1_0::
   0082                      36 	.ds 1
   0083                      37 __mullong_sloc1_1_0::
   0083                      38 	.ds 2
   0085                      39 __mullong_sloc2_1_0::
   0085                      40 	.ds 2
   0087                      41 __mullong_sloc3_1_0::
   0087                      42 	.ds 4
                             43 ;--------------------------------------------------------
                             44 ; absolute external ram data
                             45 ;--------------------------------------------------------
                             46 	.area XABS    (ABS)
                             47 ;--------------------------------------------------------
                             48 ; external initialized ram data
                             49 ;--------------------------------------------------------
                             50 	.area XISEG
                             51 ;--------------------------------------------------------
                             52 ; extended address mode data
                             53 ;--------------------------------------------------------
                             54 	.area XSEG
   0082                      55 __mullong_PARM_1:
   0082                      56 	.ds 4
   0086                      57 __mullong_PARM_2:
   0086                      58 	.ds 4
   008A                      59 __mullong_t_1_1:
   008A                      60 	.ds 4
                             61 ;--------------------------------------------------------
                             62 ; global & static initialisations
                             63 ;--------------------------------------------------------
                             64 	.area HOME (CODE)
                             65 	.area GSINIT (CODE)
                             66 	.area GSFINAL (CODE)
                             67 	.area GSINIT (CODE)
                             68 ;--------------------------------------------------------
                             69 ; Home
                             70 ;--------------------------------------------------------
                             71 	.area HOME (CODE)
                             72 	.area HOME (CODE)
                             73 ;--------------------------------------------------------
                             74 ; code
                             75 ;--------------------------------------------------------
                             76 	.area CSEG (CODE)
                             77 ;------------------------------------------------------------
                             78 ;Allocation info for local variables in function '_mullong'
                             79 ;------------------------------------------------------------
                             80 ;a                         Allocated with name '__mullong_PARM_1'
                             81 ;b                         Allocated with name '__mullong_PARM_2'
                             82 ;t                         Allocated with name '__mullong_t_1_1'
                             83 ;sloc0                     Allocated with name '__mullong_sloc0_1_0'
                             84 ;sloc1                     Allocated with name '__mullong_sloc1_1_0'
                             85 ;sloc2                     Allocated with name '__mullong_sloc2_1_0'
                             86 ;sloc3                     Allocated with name '__mullong_sloc3_1_0'
                             87 ;------------------------------------------------------------
                             88 ;sdcc-mullong.c:60: _mullong (long a, long b)
                             89 ;	-----------------------------------------
                             90 ;	 function _mullong
                             91 ;	-----------------------------------------
   8000                      92 __mullong:
                             93 ;sdcc-mullong.c:64: t.i.hi = bcast(a)->b.b0 * bcast(b)->b.b2;           // A
   8000 C6 00 82             94 	lda	__mullong_PARM_1
   8003 B7 82                95 	sta	*__mullong_sloc0_1_0
   8005 C6 00 88             96 	lda	(__mullong_PARM_2 + 0x0002)
   8008 BE 82                97 	ldx	*__mullong_sloc0_1_0
   800A 42                   98 	mul
   800B B7 84                99 	sta	*(__mullong_sloc1_1_0 + 1)
   800D BF 83               100 	stx	*__mullong_sloc1_1_0
   800F B6 83               101 	lda	*__mullong_sloc1_1_0
   8011 C7 00 8C            102 	sta	(__mullong_t_1_1 + 0x0002)
   8014 B6 84               103 	lda	*(__mullong_sloc1_1_0 + 1)
   8016 C7 00 8D            104 	sta	((__mullong_t_1_1 + 0x0002) + 1)
                            105 ;sdcc-mullong.c:65: t.i.lo = bcast(a)->b.b0 * bcast(b)->b.b0;           // A
   8019 C6 00 82            106 	lda	__mullong_PARM_1
   801C B7 83               107 	sta	*__mullong_sloc1_1_0
   801E C6 00 86            108 	lda	__mullong_PARM_2
   8021 BE 83               109 	ldx	*__mullong_sloc1_1_0
   8023 42                  110 	mul
   8024 B7 84               111 	sta	*(__mullong_sloc1_1_0 + 1)
   8026 BF 83               112 	stx	*__mullong_sloc1_1_0
   8028 B6 83               113 	lda	*__mullong_sloc1_1_0
   802A C7 00 8A            114 	sta	__mullong_t_1_1
   802D B6 84               115 	lda	*(__mullong_sloc1_1_0 + 1)
   802F C7 00 8B            116 	sta	(__mullong_t_1_1 + 1)
                            117 ;sdcc-mullong.c:66: t.b.b3 += bcast(a)->b.b3 * bcast(b)->b.b0;          // G
   8032 C6 00 8D            118 	lda	(__mullong_t_1_1 + 0x0003)
   8035 B7 83               119 	sta	*__mullong_sloc1_1_0
   8037 C6 00 85            120 	lda	(__mullong_PARM_1 + 0x0003)
   803A B7 82               121 	sta	*__mullong_sloc0_1_0
   803C C6 00 86            122 	lda	__mullong_PARM_2
   803F BE 82               123 	ldx	*__mullong_sloc0_1_0
   8041 42                  124 	mul
   8042 BB 83               125 	add	*__mullong_sloc1_1_0
                            126 ;sdcc-mullong.c:67: t.b.b3 += bcast(a)->b.b2 * bcast(b)->b.b1;          // F
   8044 C7 00 8D            127 	sta	(__mullong_t_1_1 + 0x0003)
   8047 B7 83               128 	sta	*__mullong_sloc1_1_0
   8049 C6 00 84            129 	lda	(__mullong_PARM_1 + 0x0002)
   804C B7 82               130 	sta	*__mullong_sloc0_1_0
   804E C6 00 87            131 	lda	(__mullong_PARM_2 + 0x0001)
   8051 BE 82               132 	ldx	*__mullong_sloc0_1_0
   8053 42                  133 	mul
   8054 BB 83               134 	add	*__mullong_sloc1_1_0
   8056 C7 00 8D            135 	sta	(__mullong_t_1_1 + 0x0003)
                            136 ;sdcc-mullong.c:68: t.i.hi += bcast(a)->b.b2 * bcast(b)->b.b0;          // E <- b lost in .lst
   8059 C6 00 8C            137 	lda	(__mullong_t_1_1 + 0x0002)
   805C B7 83               138 	sta	*__mullong_sloc1_1_0
   805E C6 00 8D            139 	lda	((__mullong_t_1_1 + 0x0002) + 1)
   8061 B7 84               140 	sta	*(__mullong_sloc1_1_0 + 1)
   8063 C6 00 84            141 	lda	(__mullong_PARM_1 + 0x0002)
   8066 B7 82               142 	sta	*__mullong_sloc0_1_0
   8068 C6 00 86            143 	lda	__mullong_PARM_2
   806B BE 82               144 	ldx	*__mullong_sloc0_1_0
   806D 42                  145 	mul
   806E B7 86               146 	sta	*(__mullong_sloc2_1_0 + 1)
   8070 BF 85               147 	stx	*__mullong_sloc2_1_0
   8072 B6 84               148 	lda	*(__mullong_sloc1_1_0 + 1)
   8074 BB 86               149 	add	*(__mullong_sloc2_1_0 + 1)
   8076 B7 86               150 	sta	*(__mullong_sloc2_1_0 + 1)
   8078 B6 83               151 	lda	*__mullong_sloc1_1_0
   807A B9 85               152 	adc	*__mullong_sloc2_1_0
   807C B7 85               153 	sta	*__mullong_sloc2_1_0
   807E C7 00 8C            154 	sta	(__mullong_t_1_1 + 0x0002)
   8081 B6 86               155 	lda	*(__mullong_sloc2_1_0 + 1)
   8083 C7 00 8D            156 	sta	((__mullong_t_1_1 + 0x0002) + 1)
                            157 ;sdcc-mullong.c:70: t.i.hi += bcast(a)->b.b1 * bcast(b)->b.b1;          // D <- b lost in .lst
   8086 C6 00 8C            158 	lda	(__mullong_t_1_1 + 0x0002)
   8089 B7 85               159 	sta	*__mullong_sloc2_1_0
   808B C6 00 8D            160 	lda	((__mullong_t_1_1 + 0x0002) + 1)
   808E B7 86               161 	sta	*(__mullong_sloc2_1_0 + 1)
   8090 C6 00 83            162 	lda	(__mullong_PARM_1 + 0x0001)
   8093 B7 83               163 	sta	*__mullong_sloc1_1_0
   8095 C6 00 87            164 	lda	(__mullong_PARM_2 + 0x0001)
   8098 BE 83               165 	ldx	*__mullong_sloc1_1_0
   809A 42                  166 	mul
   809B B7 84               167 	sta	*(__mullong_sloc1_1_0 + 1)
   809D BF 83               168 	stx	*__mullong_sloc1_1_0
   809F B6 86               169 	lda	*(__mullong_sloc2_1_0 + 1)
   80A1 BB 84               170 	add	*(__mullong_sloc1_1_0 + 1)
   80A3 B7 86               171 	sta	*(__mullong_sloc2_1_0 + 1)
   80A5 B6 85               172 	lda	*__mullong_sloc2_1_0
   80A7 B9 83               173 	adc	*__mullong_sloc1_1_0
   80A9 B7 85               174 	sta	*__mullong_sloc2_1_0
   80AB C7 00 8C            175 	sta	(__mullong_t_1_1 + 0x0002)
   80AE B6 86               176 	lda	*(__mullong_sloc2_1_0 + 1)
   80B0 C7 00 8D            177 	sta	((__mullong_t_1_1 + 0x0002) + 1)
                            178 ;sdcc-mullong.c:72: bcast(a)->bi.b3 = bcast(a)->b.b1 * bcast(b)->b.b2;  // C
   80B3 C6 00 83            179 	lda	(__mullong_PARM_1 + 0x0001)
   80B6 B7 85               180 	sta	*__mullong_sloc2_1_0
   80B8 C6 00 88            181 	lda	(__mullong_PARM_2 + 0x0002)
   80BB BE 85               182 	ldx	*__mullong_sloc2_1_0
   80BD 42                  183 	mul
   80BE C7 00 85            184 	sta	(__mullong_PARM_1 + 0x0003)
                            185 ;sdcc-mullong.c:73: bcast(a)->bi.i12 = bcast(a)->b.b1 * bcast(b)->b.b0; // C
   80C1 C6 00 83            186 	lda	(__mullong_PARM_1 + 0x0001)
   80C4 B7 85               187 	sta	*__mullong_sloc2_1_0
   80C6 C6 00 86            188 	lda	__mullong_PARM_2
   80C9 BE 85               189 	ldx	*__mullong_sloc2_1_0
   80CB 42                  190 	mul
   80CC B7 86               191 	sta	*(__mullong_sloc2_1_0 + 1)
   80CE BF 85               192 	stx	*__mullong_sloc2_1_0
   80D0 B6 85               193 	lda	*__mullong_sloc2_1_0
   80D2 C7 00 83            194 	sta	(__mullong_PARM_1 + 0x0001)
   80D5 B6 86               195 	lda	*(__mullong_sloc2_1_0 + 1)
   80D7 C7 00 84            196 	sta	((__mullong_PARM_1 + 0x0001) + 1)
                            197 ;sdcc-mullong.c:75: bcast(b)->bi.b3 = bcast(a)->b.b0 * bcast(b)->b.b3;  // B
   80DA C6 00 82            198 	lda	__mullong_PARM_1
   80DD B7 85               199 	sta	*__mullong_sloc2_1_0
   80DF C6 00 89            200 	lda	(__mullong_PARM_2 + 0x0003)
   80E2 BE 85               201 	ldx	*__mullong_sloc2_1_0
   80E4 42                  202 	mul
   80E5 C7 00 89            203 	sta	(__mullong_PARM_2 + 0x0003)
                            204 ;sdcc-mullong.c:76: bcast(b)->bi.i12 = bcast(a)->b.b0 * bcast(b)->b.b1; // B
   80E8 C6 00 82            205 	lda	__mullong_PARM_1
   80EB B7 85               206 	sta	*__mullong_sloc2_1_0
   80ED C6 00 87            207 	lda	(__mullong_PARM_2 + 0x0001)
   80F0 BE 85               208 	ldx	*__mullong_sloc2_1_0
   80F2 42                  209 	mul
   80F3 B7 86               210 	sta	*(__mullong_sloc2_1_0 + 1)
   80F5 BF 85               211 	stx	*__mullong_sloc2_1_0
   80F7 B6 85               212 	lda	*__mullong_sloc2_1_0
   80F9 C7 00 87            213 	sta	(__mullong_PARM_2 + 0x0001)
   80FC B6 86               214 	lda	*(__mullong_sloc2_1_0 + 1)
   80FE C7 00 88            215 	sta	((__mullong_PARM_2 + 0x0001) + 1)
                            216 ;sdcc-mullong.c:78: bcast(b)->bi.b0 = 0;                                // B
                            217 ;sdcc-mullong.c:79: bcast(a)->bi.b0 = 0;                                // C
   8101 4F                  218 	clra
   8102 C7 00 86            219 	sta	__mullong_PARM_2
   8105 C7 00 82            220 	sta	__mullong_PARM_1
                            221 ;sdcc-mullong.c:80: t.l += a;
   8108 C6 00 8A            222 	lda	__mullong_t_1_1
   810B B7 87               223 	sta	*__mullong_sloc3_1_0
   810D C6 00 8B            224 	lda	(__mullong_t_1_1 + 1)
   8110 B7 88               225 	sta	*(__mullong_sloc3_1_0 + 1)
   8112 C6 00 8C            226 	lda	(__mullong_t_1_1 + 2)
   8115 B7 89               227 	sta	*(__mullong_sloc3_1_0 + 2)
   8117 C6 00 8D            228 	lda	(__mullong_t_1_1 + 3)
   811A B7 8A               229 	sta	*(__mullong_sloc3_1_0 + 3)
   811C CB 00 85            230 	add	(__mullong_PARM_1 + 3)
   811F B7 8A               231 	sta	*(__mullong_sloc3_1_0 + 3)
   8121 B6 89               232 	lda	*(__mullong_sloc3_1_0 + 2)
   8123 C9 00 84            233 	adc	(__mullong_PARM_1 + 2)
   8126 B7 89               234 	sta	*(__mullong_sloc3_1_0 + 2)
   8128 B6 88               235 	lda	*(__mullong_sloc3_1_0 + 1)
   812A C9 00 83            236 	adc	(__mullong_PARM_1 + 1)
   812D B7 88               237 	sta	*(__mullong_sloc3_1_0 + 1)
   812F B6 87               238 	lda	*__mullong_sloc3_1_0
   8131 C9 00 82            239 	adc	__mullong_PARM_1
   8134 B7 87               240 	sta	*__mullong_sloc3_1_0
   8136 C7 00 8A            241 	sta	__mullong_t_1_1
   8139 B6 88               242 	lda	*(__mullong_sloc3_1_0 + 1)
   813B C7 00 8B            243 	sta	(__mullong_t_1_1 + 1)
   813E B6 89               244 	lda	*(__mullong_sloc3_1_0 + 2)
   8140 C7 00 8C            245 	sta	(__mullong_t_1_1 + 2)
   8143 B6 8A               246 	lda	*(__mullong_sloc3_1_0 + 3)
   8145 C7 00 8D            247 	sta	(__mullong_t_1_1 + 3)
                            248 ;sdcc-mullong.c:82: return t.l + b;
   8148 C6 00 8A            249 	lda	__mullong_t_1_1
   814B B7 87               250 	sta	*__mullong_sloc3_1_0
   814D C6 00 8B            251 	lda	(__mullong_t_1_1 + 1)
   8150 B7 88               252 	sta	*(__mullong_sloc3_1_0 + 1)
   8152 C6 00 8C            253 	lda	(__mullong_t_1_1 + 2)
   8155 B7 89               254 	sta	*(__mullong_sloc3_1_0 + 2)
   8157 C6 00 8D            255 	lda	(__mullong_t_1_1 + 3)
   815A B7 8A               256 	sta	*(__mullong_sloc3_1_0 + 3)
   815C CB 00 89            257 	add	(__mullong_PARM_2 + 3)
   815F B7 8A               258 	sta	*(__mullong_sloc3_1_0 + 3)
   8161 B6 89               259 	lda	*(__mullong_sloc3_1_0 + 2)
   8163 C9 00 88            260 	adc	(__mullong_PARM_2 + 2)
   8166 B7 89               261 	sta	*(__mullong_sloc3_1_0 + 2)
   8168 B6 88               262 	lda	*(__mullong_sloc3_1_0 + 1)
   816A C9 00 87            263 	adc	(__mullong_PARM_2 + 1)
   816D B7 88               264 	sta	*(__mullong_sloc3_1_0 + 1)
   816F B6 87               265 	lda	*__mullong_sloc3_1_0
   8171 C9 00 86            266 	adc	__mullong_PARM_2
   8174 B7 87               267 	sta	*__mullong_sloc3_1_0
   8176 4E 87 81            268 	mov	*__mullong_sloc3_1_0,*__ret3
   8179 4E 88 80            269 	mov	*(__mullong_sloc3_1_0 + 1),*__ret2
   817C BE 89               270 	ldx	*(__mullong_sloc3_1_0 + 2)
   817E B6 8A               271 	lda	*(__mullong_sloc3_1_0 + 3)
   8180                     272 00101$:
   8180 81                  273 	rts
                            274 	.area CSEG (CODE)
                            275 	.area CONST   (CODE)
                            276 	.area XINIT
                            277 	.area CABS    (ABS,CODE)
