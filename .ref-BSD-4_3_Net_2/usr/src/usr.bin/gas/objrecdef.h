begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  *	$OBJRECDEF  *	Generated automatically by "vms_struct Version 1.00"  *	Created from VMS definition file "objrecdef.mar"  *	Mon Oct 14 14:01:29 1985  *  */
end_comment

begin_struct
struct|struct
name|OBJREC
block|{
name|unsigned
name|char
name|obj$b_rectyp
decl_stmt|;
name|unsigned
name|char
name|obj$b_subtyp
decl_stmt|;
name|unsigned
name|char
name|obj$b_mhd_strlv
decl_stmt|;
name|unsigned
name|char
name|obj$b_mhd_recsz
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|obj$t_mhd_name
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_define
define|#
directive|define
name|OBJ$C_HDR
value|0
end_define

begin_define
define|#
directive|define
name|OBJ$C_HDR_MHD
value|0
end_define

begin_define
define|#
directive|define
name|OBJ$C_HDR_LNM
value|1
end_define

begin_define
define|#
directive|define
name|OBJ$C_HDR_SRC
value|2
end_define

begin_define
define|#
directive|define
name|OBJ$C_HDR_TTL
value|3
end_define

begin_define
define|#
directive|define
name|OBJ$C_HDR_CPR
value|4
end_define

begin_define
define|#
directive|define
name|OBJ$C_HDR_MTC
value|5
end_define

begin_define
define|#
directive|define
name|OBJ$C_HDR_GTX
value|6
end_define

begin_define
define|#
directive|define
name|OBJ$C_GSD
value|1
end_define

begin_define
define|#
directive|define
name|OBJ$C_GSD_PSC
value|0
end_define

begin_define
define|#
directive|define
name|OBJ$C_GSD_SYM
value|1
end_define

begin_define
define|#
directive|define
name|OBJ$C_GSD_EPM
value|2
end_define

begin_define
define|#
directive|define
name|OBJ$C_GSD_PRO
value|3
end_define

begin_define
define|#
directive|define
name|OBJ$C_GSD_SYMW
value|4
end_define

begin_define
define|#
directive|define
name|OBJ$C_GSD_EPMW
value|5
end_define

begin_define
define|#
directive|define
name|OBJ$C_GSD_PROW
value|6
end_define

begin_define
define|#
directive|define
name|OBJ$C_GSD_IDC
value|7
end_define

begin_define
define|#
directive|define
name|OBJ$C_GSD_ENV
value|8
end_define

begin_define
define|#
directive|define
name|OBJ$C_GSD_LSY
value|9
end_define

begin_define
define|#
directive|define
name|OBJ$C_GSD_LEPM
value|10
end_define

begin_define
define|#
directive|define
name|OBJ$C_GSD_LPRO
value|11
end_define

begin_define
define|#
directive|define
name|OBJ$C_GSD_SPSC
value|12
end_define

begin_define
define|#
directive|define
name|OBJ$C_TIR
value|2
end_define

begin_define
define|#
directive|define
name|OBJ$C_EOM
value|3
end_define

begin_define
define|#
directive|define
name|OBJ$C_DBG
value|4
end_define

begin_define
define|#
directive|define
name|OBJ$C_TBT
value|5
end_define

begin_define
define|#
directive|define
name|OBJ$C_LNK
value|6
end_define

begin_define
define|#
directive|define
name|OBJ$C_EOMW
value|7
end_define

begin_define
define|#
directive|define
name|OBJ$C_MAXRECTYP
value|7
end_define

begin_define
define|#
directive|define
name|OBJ$K_SUBTYP
value|1
end_define

begin_define
define|#
directive|define
name|OBJ$C_SUBTYP
value|1
end_define

begin_define
define|#
directive|define
name|OBJ$C_MAXRECSIZ
value|2048
end_define

begin_define
define|#
directive|define
name|OBJ$C_STRLVL
value|0
end_define

begin_define
define|#
directive|define
name|OBJ$C_SYMSIZ
value|31
end_define

begin_define
define|#
directive|define
name|OBJ$C_STOREPLIM
value|-1
end_define

begin_define
define|#
directive|define
name|OBJ$C_PSCALILIM
value|9
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|MHD$C_MHD
value|0
end_define

begin_define
define|#
directive|define
name|MHD$C_LNM
value|1
end_define

begin_define
define|#
directive|define
name|MHD$C_SRC
value|2
end_define

begin_define
define|#
directive|define
name|MHD$C_TTL
value|3
end_define

begin_define
define|#
directive|define
name|MHD$C_CPR
value|4
end_define

begin_define
define|#
directive|define
name|MHD$C_MTC
value|5
end_define

begin_define
define|#
directive|define
name|MHD$C_GTX
value|6
end_define

begin_define
define|#
directive|define
name|MHD$C_MAXHDRTYP
value|6
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|GSD$K_ENTRIES
value|1
end_define

begin_define
define|#
directive|define
name|GSD$C_ENTRIES
value|1
end_define

begin_define
define|#
directive|define
name|GSD$C_PSC
value|0
end_define

begin_define
define|#
directive|define
name|GSD$C_SYM
value|1
end_define

begin_define
define|#
directive|define
name|GSD$C_EPM
value|2
end_define

begin_define
define|#
directive|define
name|GSD$C_PRO
value|3
end_define

begin_define
define|#
directive|define
name|GSD$C_SYMW
value|4
end_define

begin_define
define|#
directive|define
name|GSD$C_EPMW
value|5
end_define

begin_define
define|#
directive|define
name|GSD$C_PROW
value|6
end_define

begin_define
define|#
directive|define
name|GSD$C_IDC
value|7
end_define

begin_define
define|#
directive|define
name|GSD$C_ENV
value|8
end_define

begin_define
define|#
directive|define
name|GSD$C_LSY
value|9
end_define

begin_define
define|#
directive|define
name|GSD$C_LEPM
value|10
end_define

begin_define
define|#
directive|define
name|GSD$C_LPRO
value|11
end_define

begin_define
define|#
directive|define
name|GSD$C_SPSC
value|12
end_define

begin_define
define|#
directive|define
name|GSD$C_SYMV
value|13
end_define

begin_define
define|#
directive|define
name|GSD$C_EPMV
value|14
end_define

begin_define
define|#
directive|define
name|GSD$C_PROV
value|15
end_define

begin_define
define|#
directive|define
name|GSD$C_MAXRECTYP
value|15
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|GSY$M_WEAK
value|1
end_define

begin_define
define|#
directive|define
name|GSY$M_DEF
value|2
end_define

begin_define
define|#
directive|define
name|GSY$M_UNI
value|4
end_define

begin_define
define|#
directive|define
name|GSY$M_REL
value|8
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|GPS$M_PIC
value|1
end_define

begin_define
define|#
directive|define
name|GPS$M_LIB
value|2
end_define

begin_define
define|#
directive|define
name|GPS$M_OVR
value|4
end_define

begin_define
define|#
directive|define
name|GPS$M_REL
value|8
end_define

begin_define
define|#
directive|define
name|GPS$M_GBL
value|16
end_define

begin_define
define|#
directive|define
name|GPS$M_SHR
value|32
end_define

begin_define
define|#
directive|define
name|GPS$M_EXE
value|64
end_define

begin_define
define|#
directive|define
name|GPS$M_RD
value|128
end_define

begin_define
define|#
directive|define
name|GPS$M_WRT
value|256
end_define

begin_define
define|#
directive|define
name|GPS$M_VEC
value|512
end_define

begin_define
define|#
directive|define
name|GPS$K_NAME
value|9
end_define

begin_define
define|#
directive|define
name|GPS$C_NAME
value|9
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|TIR$C_STA_GBL
value|0
end_define

begin_define
define|#
directive|define
name|TIR$C_STA_SB
value|1
end_define

begin_define
define|#
directive|define
name|TIR$C_STA_SW
value|2
end_define

begin_define
define|#
directive|define
name|TIR$C_STA_LW
value|3
end_define

begin_define
define|#
directive|define
name|TIR$C_STA_PB
value|4
end_define

begin_define
define|#
directive|define
name|TIR$C_STA_PW
value|5
end_define

begin_define
define|#
directive|define
name|TIR$C_STA_PL
value|6
end_define

begin_define
define|#
directive|define
name|TIR$C_STA_UB
value|7
end_define

begin_define
define|#
directive|define
name|TIR$C_STA_UW
value|8
end_define

begin_define
define|#
directive|define
name|TIR$C_STA_BFI
value|9
end_define

begin_define
define|#
directive|define
name|TIR$C_STA_WFI
value|10
end_define

begin_define
define|#
directive|define
name|TIR$C_STA_LFI
value|11
end_define

begin_define
define|#
directive|define
name|TIR$C_STA_EPM
value|12
end_define

begin_define
define|#
directive|define
name|TIR$C_STA_CKARG
value|13
end_define

begin_define
define|#
directive|define
name|TIR$C_STA_WPB
value|14
end_define

begin_define
define|#
directive|define
name|TIR$C_STA_WPW
value|15
end_define

begin_define
define|#
directive|define
name|TIR$C_STA_WPL
value|16
end_define

begin_define
define|#
directive|define
name|TIR$C_STA_LSY
value|17
end_define

begin_define
define|#
directive|define
name|TIR$C_STA_LIT
value|18
end_define

begin_define
define|#
directive|define
name|TIR$C_STA_LEPM
value|19
end_define

begin_define
define|#
directive|define
name|TIR$C_MAXSTACOD
value|19
end_define

begin_define
define|#
directive|define
name|TIR$C_MINSTOCOD
value|20
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_SB
value|20
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_SW
value|21
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_L
value|22
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_BD
value|23
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_WD
value|24
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_LD
value|25
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_LI
value|26
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_PIDR
value|27
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_PICR
value|28
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_RSB
value|29
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_RSW
value|30
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_RL
value|31
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_VPS
value|32
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_USB
value|33
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_USW
value|34
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_RUB
value|35
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_RUW
value|36
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_B
value|37
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_W
value|38
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_RB
value|39
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_RW
value|40
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_RIVB
value|41
end_define

begin_define
define|#
directive|define
name|TIR$C_STO_PIRR
value|42
end_define

begin_define
define|#
directive|define
name|TIR$C_MAXSTOCOD
value|42
end_define

begin_define
define|#
directive|define
name|TIR$C_MINOPRCOD
value|50
end_define

begin_define
define|#
directive|define
name|TIR$C_OPR_NOP
value|50
end_define

begin_define
define|#
directive|define
name|TIR$C_OPR_ADD
value|51
end_define

begin_define
define|#
directive|define
name|TIR$C_OPR_SUB
value|52
end_define

begin_define
define|#
directive|define
name|TIR$C_OPR_MUL
value|53
end_define

begin_define
define|#
directive|define
name|TIR$C_OPR_DIV
value|54
end_define

begin_define
define|#
directive|define
name|TIR$C_OPR_AND
value|55
end_define

begin_define
define|#
directive|define
name|TIR$C_OPR_IOR
value|56
end_define

begin_define
define|#
directive|define
name|TIR$C_OPR_EOR
value|57
end_define

begin_define
define|#
directive|define
name|TIR$C_OPR_NEG
value|58
end_define

begin_define
define|#
directive|define
name|TIR$C_OPR_COM
value|59
end_define

begin_define
define|#
directive|define
name|TIR$C_OPR_INSV
value|60
end_define

begin_define
define|#
directive|define
name|TIR$C_OPR_ASH
value|61
end_define

begin_define
define|#
directive|define
name|TIR$C_OPR_USH
value|62
end_define

begin_define
define|#
directive|define
name|TIR$C_OPR_ROT
value|63
end_define

begin_define
define|#
directive|define
name|TIR$C_OPR_SEL
value|64
end_define

begin_define
define|#
directive|define
name|TIR$C_OPR_REDEF
value|65
end_define

begin_define
define|#
directive|define
name|TIR$C_OPR_DFLIT
value|66
end_define

begin_define
define|#
directive|define
name|TIR$C_MAXOPRCOD
value|66
end_define

begin_define
define|#
directive|define
name|TIR$C_MINCTLCOD
value|80
end_define

begin_define
define|#
directive|define
name|TIR$C_CTL_SETRB
value|80
end_define

begin_define
define|#
directive|define
name|TIR$C_CTL_AUGRB
value|81
end_define

begin_define
define|#
directive|define
name|TIR$C_CTL_DFLOC
value|82
end_define

begin_define
define|#
directive|define
name|TIR$C_CTL_STLOC
value|83
end_define

begin_define
define|#
directive|define
name|TIR$C_CTL_STKDL
value|84
end_define

begin_define
define|#
directive|define
name|TIR$C_MAXCTLCOD
value|84
end_define

begin_escape
end_escape

begin_comment
comment|/*  *	Debugger symbol definitions:  These are done by hand, as no  *					machine-readable version seems  *					to be available.  */
end_comment

begin_define
define|#
directive|define
name|DST$C_C
value|7
end_define

begin_comment
comment|/* Language == "C"	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_VERSION
value|153
end_define

begin_define
define|#
directive|define
name|DST$C_SOURCE
value|155
end_define

begin_comment
comment|/* Source file		*/
end_comment

begin_define
define|#
directive|define
name|DST$C_PROLOG
value|162
end_define

begin_define
define|#
directive|define
name|DST$C_BLKBEG
value|176
end_define

begin_comment
comment|/* Beginning of block	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_BLKEND
value|177
end_define

begin_comment
comment|/* End of block	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_ENTRY
value|181
end_define

begin_define
define|#
directive|define
name|DST$C_PSECT
value|184
end_define

begin_define
define|#
directive|define
name|DST$C_LINE_NUM
value|185
end_define

begin_comment
comment|/* Line Number		*/
end_comment

begin_define
define|#
directive|define
name|DST$C_LBLORLIT
value|186
end_define

begin_define
define|#
directive|define
name|DST$C_LABEL
value|187
end_define

begin_define
define|#
directive|define
name|DST$C_MODBEG
value|188
end_define

begin_comment
comment|/* Beginning of module	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_MODEND
value|189
end_define

begin_comment
comment|/* End of module	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_RTNBEG
value|190
end_define

begin_comment
comment|/* Beginning of routine	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_RTNEND
value|191
end_define

begin_comment
comment|/* End of routine	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_DELTA_PC_W
value|1
end_define

begin_comment
comment|/* Incr PC	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_INCR_LINUM
value|2
end_define

begin_comment
comment|/* Incr Line #	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_INCR_LINUM_W
value|3
end_define

begin_comment
comment|/* Incr Line #	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_SET_LINUM_INCR
value|4
end_define

begin_define
define|#
directive|define
name|DST$C_SET_LINUM_INCR_W
value|5
end_define

begin_define
define|#
directive|define
name|DST$C_RESET_LINUM_INCR
value|6
end_define

begin_define
define|#
directive|define
name|DST$C_BEG_STMT_MODE
value|7
end_define

begin_define
define|#
directive|define
name|DST$C_END_STMT_MODE
value|8
end_define

begin_define
define|#
directive|define
name|DST$C_SET_LINE_NUM
value|9
end_define

begin_comment
comment|/* Set Line #	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_SET_PC
value|10
end_define

begin_define
define|#
directive|define
name|DST$C_SET_PC_W
value|11
end_define

begin_define
define|#
directive|define
name|DST$C_SET_PC_L
value|12
end_define

begin_define
define|#
directive|define
name|DST$C_SET_STMTNUM
value|13
end_define

begin_define
define|#
directive|define
name|DST$C_TERM
value|14
end_define

begin_comment
comment|/* End of lines	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_TERM_W
value|15
end_define

begin_comment
comment|/* End of lines	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_SET_ABS_PC
value|16
end_define

begin_comment
comment|/* Set PC	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_DELTA_PC_L
value|17
end_define

begin_comment
comment|/* Incr PC	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_INCR_LINUM_L
value|18
end_define

begin_comment
comment|/* Incr Line #	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_SET_LINUM_B
value|19
end_define

begin_comment
comment|/* Set Line #	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_SET_LINUM_L
value|20
end_define

begin_comment
comment|/* Set Line #	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_TERM_L
value|21
end_define

begin_comment
comment|/* End of lines	*/
end_comment

begin_comment
comment|/* these are used with DST$C_SOURCE */
end_comment

begin_define
define|#
directive|define
name|DST$C_SRC_FORMFEED
value|16
end_define

begin_comment
comment|/* ^L counts	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_SRC_DECLFILE
value|1
end_define

begin_comment
comment|/* Declare file	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_SRC_SETFILE
value|2
end_define

begin_comment
comment|/* Set file	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_SRC_SETREC_L
value|3
end_define

begin_comment
comment|/* Set record	*/
end_comment

begin_define
define|#
directive|define
name|DST$C_SRC_DEFLINES_W
value|10
end_define

begin_comment
comment|/* # of line	*/
end_comment

begin_comment
comment|/* the following are the codes for the various data types.  Anything not on  * the list is included under 'advanced_type'  */
end_comment

begin_define
define|#
directive|define
name|DBG$C_UCHAR
value|0x02
end_define

begin_define
define|#
directive|define
name|DBG$C_USINT
value|0x03
end_define

begin_define
define|#
directive|define
name|DBG$C_ULINT
value|0x04
end_define

begin_define
define|#
directive|define
name|DBG$C_SCHAR
value|0x06
end_define

begin_define
define|#
directive|define
name|DBG$C_SSINT
value|0x07
end_define

begin_define
define|#
directive|define
name|DBG$C_SLINT
value|0x08
end_define

begin_define
define|#
directive|define
name|DBG$C_REAL4
value|0x0a
end_define

begin_define
define|#
directive|define
name|DBG$C_REAL8
value|0x0b
end_define

begin_define
define|#
directive|define
name|DBG$C_FUNCTION_ADDR
value|0x17
end_define

begin_define
define|#
directive|define
name|DBG$C_ADVANCED_TYPE
value|0xa3
end_define

begin_comment
comment|/*  These are the codes that are used to generate the definitions of struct  *  union and enum records  */
end_comment

begin_define
define|#
directive|define
name|DBG$C_ENUM_ITEM
value|0xa4
end_define

begin_define
define|#
directive|define
name|DBG$C_ENUM_START
value|0xa5
end_define

begin_define
define|#
directive|define
name|DBG$C_ENUM_END
value|0xa6
end_define

begin_define
define|#
directive|define
name|DBG$C_STRUCT_START
value|0xab
end_define

begin_define
define|#
directive|define
name|DBG$C_STRUCT_ITEM
value|0xff
end_define

begin_define
define|#
directive|define
name|DBG$C_STRUCT_END
value|0xac
end_define

begin_comment
comment|/*  These are the codes that are used in the suffix records to determine the  *  actual data type  */
end_comment

begin_define
define|#
directive|define
name|DBG$C_BASIC
value|0x01
end_define

begin_define
define|#
directive|define
name|DBG$C_BASIC_ARRAY
value|0x02
end_define

begin_define
define|#
directive|define
name|DBG$C_STRUCT
value|0x03
end_define

begin_define
define|#
directive|define
name|DBG$C_POINTER
value|0x04
end_define

begin_define
define|#
directive|define
name|DBG$C_VOID
value|0x05
end_define

begin_define
define|#
directive|define
name|DBG$C_COMPLEX_ARRAY
value|0x07
end_define

begin_comment
comment|/* These codes are used in the generation of the symbol definition records  */
end_comment

begin_define
define|#
directive|define
name|DBG$C_FUNCTION_PARAMETER
value|0xc9
end_define

begin_define
define|#
directive|define
name|DBG$C_LOCAL_SYM
value|0xd9
end_define

end_unit

