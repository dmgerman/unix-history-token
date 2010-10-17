begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_undef
undef|#
directive|undef
name|vms
end_undef

begin_comment
comment|/* vms.h -- Header file for VMS (Alpha and Vax) support.    Copyright 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003    Free Software Foundation, Inc.     Written by Klaus K"ampf (kkaempf@rmi.de)  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMS_H
end_ifndef

begin_define
define|#
directive|define
name|VMS_H
end_define

begin_comment
comment|/* Constants starting with 'Exxx_' are for openVMS/Alpha (EVAX object language)  */
end_comment

begin_comment
comment|/* VMS Text, information and relocation record (TIR/ETIR) definitions.  */
end_comment

begin_define
define|#
directive|define
name|TIR_S_C_STA_GBL
value|0
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_SB
value|1
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_SW
value|2
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_LW
value|3
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_PB
value|4
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_PW
value|5
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_PL
value|6
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_UB
value|7
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_UW
value|8
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_BFI
value|9
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_WFI
value|10
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_LFI
value|11
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_EPM
value|12
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_CKARG
value|13
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_WPB
value|14
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_WPW
value|15
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_WPL
value|16
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_LSY
value|17
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_LIT
value|18
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_LEPM
value|19
end_define

begin_define
define|#
directive|define
name|TIR_S_C_MAXSTACOD
value|19
end_define

begin_define
define|#
directive|define
name|TIR_S_C_MINSTOCOD
value|20
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_SB
value|20
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_SW
value|21
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_L
value|22
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_LW
value|22
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_BD
value|23
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_WD
value|24
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_LD
value|25
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_LI
value|26
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_PIDR
value|27
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_PICR
value|28
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_RSB
value|29
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_RSW
value|30
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_RL
value|31
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_VPS
value|32
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_USB
value|33
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_USW
value|34
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_RUB
value|35
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_RUW
value|36
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_B
value|37
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_W
value|38
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_RB
value|39
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_RW
value|40
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_RIVB
value|41
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_PIRR
value|42
end_define

begin_define
define|#
directive|define
name|TIR_S_C_MAXSTOCOD
value|42
end_define

begin_define
define|#
directive|define
name|TIR_S_C_MINOPRCOD
value|50
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_NOP
value|50
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_ADD
value|51
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_SUB
value|52
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_MUL
value|53
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_DIV
value|54
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_AND
value|55
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_IOR
value|56
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_EOR
value|57
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_NEG
value|58
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_COM
value|59
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_INSV
value|60
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_ASH
value|61
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_USH
value|62
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_ROT
value|63
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_SEL
value|64
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_REDEF
value|65
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_DFLIT
value|66
end_define

begin_define
define|#
directive|define
name|TIR_S_C_MAXOPRCOD
value|66
end_define

begin_define
define|#
directive|define
name|TIR_S_C_MINCTLCOD
value|80
end_define

begin_define
define|#
directive|define
name|TIR_S_C_CTL_SETRB
value|80
end_define

begin_define
define|#
directive|define
name|TIR_S_C_CTL_AUGRB
value|81
end_define

begin_define
define|#
directive|define
name|TIR_S_C_CTL_DFLOC
value|82
end_define

begin_define
define|#
directive|define
name|TIR_S_C_CTL_STLOC
value|83
end_define

begin_define
define|#
directive|define
name|TIR_S_C_CTL_STKDL
value|84
end_define

begin_define
define|#
directive|define
name|TIR_S_C_MAXCTLCOD
value|84
end_define

begin_define
define|#
directive|define
name|ETIR_S_C_MINSTACOD
value|0
end_define

begin_comment
comment|/* Minimum store code		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STA_GBL
value|0
end_define

begin_comment
comment|/* Stack global symbol value	*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STA_LW
value|1
end_define

begin_comment
comment|/* Stack longword		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STA_QW
value|2
end_define

begin_comment
comment|/* Stack quadword		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STA_PQ
value|3
end_define

begin_comment
comment|/* Stack psect base plus quadword offset  */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STA_LI
value|4
end_define

begin_comment
comment|/* Stack literal		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STA_MOD
value|5
end_define

begin_comment
comment|/* Stack module			*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STA_CKARG
value|6
end_define

begin_comment
comment|/* Check Arguments		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_MAXSTACOD
value|6
end_define

begin_comment
comment|/* Maximum stack code		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_MINSTOCOD
value|50
end_define

begin_comment
comment|/* Minimum store code		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STO_B
value|50
end_define

begin_comment
comment|/* Store byte			*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STO_W
value|51
end_define

begin_comment
comment|/* Store word			*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STO_LW
value|52
end_define

begin_comment
comment|/* Store longword		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STO_QW
value|53
end_define

begin_comment
comment|/* Store quadword		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STO_IMMR
value|54
end_define

begin_comment
comment|/* Store immediate Repeated	*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STO_GBL
value|55
end_define

begin_comment
comment|/* Store global			*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STO_CA
value|56
end_define

begin_comment
comment|/* Store code address		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STO_RB
value|57
end_define

begin_comment
comment|/* Store relative branch	*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STO_AB
value|58
end_define

begin_comment
comment|/* Store absolute branch	*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STO_OFF
value|59
end_define

begin_comment
comment|/* Store offset within psect	*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STO_IMM
value|61
end_define

begin_comment
comment|/* Store immediate		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STO_GBL_LW
value|62
end_define

begin_comment
comment|/* Store global Longword	*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STO_LP_PSB
value|63
end_define

begin_comment
comment|/* STO_LP_PSB not valid in level 2 use STC_LP_PSB			*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STO_HINT_GBL
value|64
end_define

begin_comment
comment|/* Store 14 bit HINT at global address */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STO_HINT_PS
value|65
end_define

begin_comment
comment|/* Store 14 bit HINT at psect + offset */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_MAXSTOCOD
value|65
end_define

begin_comment
comment|/* Maximum store code		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_MINOPRCOD
value|100
end_define

begin_comment
comment|/* Minimum operate code		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_OPR_NOP
value|100
end_define

begin_comment
comment|/* No-op			*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_OPR_ADD
value|101
end_define

begin_comment
comment|/* Add				*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_OPR_SUB
value|102
end_define

begin_comment
comment|/* Subtract			*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_OPR_MUL
value|103
end_define

begin_comment
comment|/* Multiply			*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_OPR_DIV
value|104
end_define

begin_comment
comment|/* Divide			*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_OPR_AND
value|105
end_define

begin_comment
comment|/* Logical AND			*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_OPR_IOR
value|106
end_define

begin_comment
comment|/* Logical inclusive OR		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_OPR_EOR
value|107
end_define

begin_comment
comment|/* Logical exclusive OR		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_OPR_NEG
value|108
end_define

begin_comment
comment|/* Negate			*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_OPR_COM
value|109
end_define

begin_comment
comment|/* Complement			*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_OPR_INSV
value|110
end_define

begin_comment
comment|/* Insert bit field		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_OPR_ASH
value|111
end_define

begin_comment
comment|/* Arithmetic shift		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_OPR_USH
value|112
end_define

begin_comment
comment|/* Unsigned shift		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_OPR_ROT
value|113
end_define

begin_comment
comment|/* Rotate			*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_OPR_SEL
value|114
end_define

begin_comment
comment|/* Select one of three longwords on top of stack  */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_OPR_REDEF
value|115
end_define

begin_comment
comment|/* Redefine this symbol after pass 2  */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_OPR_DFLIT
value|116
end_define

begin_comment
comment|/* Define a literal		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_MAXOPRCOD
value|116
end_define

begin_comment
comment|/* Maximum operate code		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_MINCTLCOD
value|150
end_define

begin_comment
comment|/* Minimum control code		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_CTL_SETRB
value|150
end_define

begin_comment
comment|/* Set relocation base		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_CTL_AUGRB
value|151
end_define

begin_comment
comment|/* Augment relocation base	*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_CTL_DFLOC
value|152
end_define

begin_comment
comment|/* Define debug location	*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_CTL_STLOC
value|153
end_define

begin_comment
comment|/* Set debug location		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_CTL_STKDL
value|154
end_define

begin_comment
comment|/* Stack debug location		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_MAXCTLCOD
value|154
end_define

begin_comment
comment|/* Maximum control code		*/
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_MINSTCCOD
value|200
end_define

begin_comment
comment|/* Minimum store-conditional code    */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STC_LP
value|200
end_define

begin_comment
comment|/* Store-conditional Linkage Pair    */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STC_LP_PSB
value|201
end_define

begin_comment
comment|/* Store-conditional Linkage Pair with Procedure Signature */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STC_GBL
value|202
end_define

begin_comment
comment|/* Store-conditional Address at global address */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STC_GCA
value|203
end_define

begin_comment
comment|/* Store-conditional Code Address at global address */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STC_PS
value|204
end_define

begin_comment
comment|/* Store-conditional Address at psect + offset */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STC_NOP_GBL
value|205
end_define

begin_comment
comment|/* Store-conditional NOP at address of global */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STC_NOP_PS
value|206
end_define

begin_comment
comment|/* Store-conditional NOP at pect + offset */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STC_BSR_GBL
value|207
end_define

begin_comment
comment|/* Store-conditional BSR at global address */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STC_BSR_PS
value|208
end_define

begin_comment
comment|/* Store-conditional BSR at pect + offset */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STC_LDA_GBL
value|209
end_define

begin_comment
comment|/* Store-conditional LDA at global address */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STC_LDA_PS
value|210
end_define

begin_comment
comment|/* Store-conditional LDA at psect + offset */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STC_BOH_GBL
value|211
end_define

begin_comment
comment|/* Store-conditional BSR or Hint at global address */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STC_BOH_PS
value|212
end_define

begin_comment
comment|/* Store-conditional BSR or Hint at pect + offset */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STC_NBH_GBL
value|213
end_define

begin_comment
comment|/* Store-conditional NOP,BSR or HINT at global address */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_STC_NBH_PS
value|214
end_define

begin_comment
comment|/* Store-conditional NOP,BSR or HINT at psect + offset */
end_comment

begin_define
define|#
directive|define
name|ETIR_S_C_MAXSTCCOD
value|214
end_define

begin_comment
comment|/* Maximum store-conditional code    */
end_comment

begin_comment
comment|/* VMS Global symbol definition record (GSD/EGSD).  */
end_comment

begin_define
define|#
directive|define
name|GSD_S_K_ENTRIES
value|1
end_define

begin_define
define|#
directive|define
name|GSD_S_C_ENTRIES
value|1
end_define

begin_define
define|#
directive|define
name|GSD_S_C_PSC
value|0
end_define

begin_define
define|#
directive|define
name|GSD_S_C_SYM
value|1
end_define

begin_define
define|#
directive|define
name|GSD_S_C_EPM
value|2
end_define

begin_define
define|#
directive|define
name|GSD_S_C_PRO
value|3
end_define

begin_define
define|#
directive|define
name|GSD_S_C_SYMW
value|4
end_define

begin_define
define|#
directive|define
name|GSD_S_C_EPMW
value|5
end_define

begin_define
define|#
directive|define
name|GSD_S_C_PROW
value|6
end_define

begin_define
define|#
directive|define
name|GSD_S_C_IDC
value|7
end_define

begin_define
define|#
directive|define
name|GSD_S_C_ENV
value|8
end_define

begin_define
define|#
directive|define
name|GSD_S_C_LSY
value|9
end_define

begin_define
define|#
directive|define
name|GSD_S_C_LEPM
value|10
end_define

begin_define
define|#
directive|define
name|GSD_S_C_LPRO
value|11
end_define

begin_define
define|#
directive|define
name|GSD_S_C_SPSC
value|12
end_define

begin_define
define|#
directive|define
name|GSD_S_C_SYMV
value|13
end_define

begin_define
define|#
directive|define
name|GSD_S_C_EPMV
value|14
end_define

begin_define
define|#
directive|define
name|GSD_S_C_PROV
value|15
end_define

begin_define
define|#
directive|define
name|GSD_S_C_MAXRECTYP
value|15
end_define

begin_define
define|#
directive|define
name|EGSD_S_K_ENTRIES
value|2
end_define

begin_comment
comment|/* Offset to first entry in record	*/
end_comment

begin_define
define|#
directive|define
name|EGSD_S_C_ENTRIES
value|2
end_define

begin_comment
comment|/* Offset to first entry in record	*/
end_comment

begin_define
define|#
directive|define
name|EGSD_S_C_PSC
value|0
end_define

begin_comment
comment|/* Psect definition			*/
end_comment

begin_define
define|#
directive|define
name|EGSD_S_C_SYM
value|1
end_define

begin_comment
comment|/* Symbol specification			*/
end_comment

begin_define
define|#
directive|define
name|EGSD_S_C_IDC
value|2
end_define

begin_comment
comment|/* Random entity check			*/
end_comment

begin_define
define|#
directive|define
name|EGSD_S_C_SPSC
value|5
end_define

begin_comment
comment|/* Shareable image psect definition	*/
end_comment

begin_define
define|#
directive|define
name|EGSD_S_C_SYMV
value|6
end_define

begin_comment
comment|/* Vectored (dual-valued) versions of SYM, */
end_comment

begin_define
define|#
directive|define
name|EGSD_S_C_SYMM
value|7
end_define

begin_comment
comment|/* Masked versions of SYM,		*/
end_comment

begin_define
define|#
directive|define
name|EGSD_S_C_SYMG
value|8
end_define

begin_comment
comment|/* EGST - gst version of SYM		*/
end_comment

begin_define
define|#
directive|define
name|EGSD_S_C_MAXRECTYP
value|8
end_define

begin_comment
comment|/* Maximum entry type defined		*/
end_comment

begin_define
define|#
directive|define
name|GPS_S_M_PIC
value|1
end_define

begin_define
define|#
directive|define
name|GPS_S_M_LIB
value|2
end_define

begin_define
define|#
directive|define
name|GPS_S_M_OVR
value|4
end_define

begin_define
define|#
directive|define
name|GPS_S_M_REL
value|8
end_define

begin_define
define|#
directive|define
name|GPS_S_M_GBL
value|16
end_define

begin_define
define|#
directive|define
name|GPS_S_M_SHR
value|32
end_define

begin_define
define|#
directive|define
name|GPS_S_M_EXE
value|64
end_define

begin_define
define|#
directive|define
name|GPS_S_M_RD
value|128
end_define

begin_define
define|#
directive|define
name|GPS_S_M_WRT
value|256
end_define

begin_define
define|#
directive|define
name|GPS_S_M_VEC
value|512
end_define

begin_define
define|#
directive|define
name|GPS_S_K_NAME
value|9
end_define

begin_define
define|#
directive|define
name|GPS_S_C_NAME
value|9
end_define

begin_define
define|#
directive|define
name|EGPS_S_V_PIC
value|0x0001
end_define

begin_define
define|#
directive|define
name|EGPS_S_V_LIB
value|0x0002
end_define

begin_define
define|#
directive|define
name|EGPS_S_V_OVR
value|0x0004
end_define

begin_define
define|#
directive|define
name|EGPS_S_V_REL
value|0x0008
end_define

begin_define
define|#
directive|define
name|EGPS_S_V_GBL
value|0x0010
end_define

begin_define
define|#
directive|define
name|EGPS_S_V_SHR
value|0x0020
end_define

begin_define
define|#
directive|define
name|EGPS_S_V_EXE
value|0x0040
end_define

begin_define
define|#
directive|define
name|EGPS_S_V_RD
value|0x0080
end_define

begin_define
define|#
directive|define
name|EGPS_S_V_WRT
value|0x0100
end_define

begin_define
define|#
directive|define
name|EGPS_S_V_VEC
value|0x0200
end_define

begin_define
define|#
directive|define
name|EGPS_S_V_NOMOD
value|0x0400
end_define

begin_define
define|#
directive|define
name|EGPS_S_V_COM
value|0x0800
end_define

begin_define
define|#
directive|define
name|GSY_S_M_WEAK
value|1
end_define

begin_define
define|#
directive|define
name|GSY_S_M_DEF
value|2
end_define

begin_define
define|#
directive|define
name|GSY_S_M_UNI
value|4
end_define

begin_define
define|#
directive|define
name|GSY_S_M_REL
value|8
end_define

begin_define
define|#
directive|define
name|EGSY_S_V_WEAK
value|0x0001
end_define

begin_define
define|#
directive|define
name|EGSY_S_V_DEF
value|0x0002
end_define

begin_define
define|#
directive|define
name|EGSY_S_V_UNI
value|0x0004
end_define

begin_define
define|#
directive|define
name|EGSY_S_V_REL
value|0x0008
end_define

begin_define
define|#
directive|define
name|EGSY_S_V_COMM
value|0x0010
end_define

begin_define
define|#
directive|define
name|EGSY_S_V_VECEP
value|0x0020
end_define

begin_define
define|#
directive|define
name|EGSY_S_V_NORM
value|0x0040
end_define

begin_define
define|#
directive|define
name|LSY_S_M_DEF
value|2
end_define

begin_define
define|#
directive|define
name|LSY_S_M_REL
value|8
end_define

begin_define
define|#
directive|define
name|ENV_S_M_DEF
value|1
end_define

begin_define
define|#
directive|define
name|ENV_S_M_NESTED
value|2
end_define

begin_comment
comment|/*  *	Debugger symbol definitions:  These are done by hand, as no  *					machine-readable version seems  *					to be available.  */
end_comment

begin_define
define|#
directive|define
name|DST_S_C_C
value|7
end_define

begin_comment
comment|/* Language == "C"	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_CXX
value|15
end_define

begin_comment
comment|/* Language == "C++"	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_VERSION
value|153
end_define

begin_define
define|#
directive|define
name|DST_S_C_SOURCE
value|155
end_define

begin_comment
comment|/* Source file		*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_PROLOG
value|162
end_define

begin_define
define|#
directive|define
name|DST_S_C_BLKBEG
value|176
end_define

begin_comment
comment|/* Beginning of block	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_BLKEND
value|177
end_define

begin_comment
comment|/* End of block	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_ENTRY
value|181
end_define

begin_define
define|#
directive|define
name|DST_S_C_PSECT
value|184
end_define

begin_define
define|#
directive|define
name|DST_S_C_LINE_NUM
value|185
end_define

begin_comment
comment|/* Line Number		*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_LBLORLIT
value|186
end_define

begin_define
define|#
directive|define
name|DST_S_C_LABEL
value|187
end_define

begin_define
define|#
directive|define
name|DST_S_C_MODBEG
value|188
end_define

begin_comment
comment|/* Beginning of module	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_MODEND
value|189
end_define

begin_comment
comment|/* End of module	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_RTNBEG
value|190
end_define

begin_comment
comment|/* Beginning of routine	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_RTNEND
value|191
end_define

begin_comment
comment|/* End of routine	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_DELTA_PC_W
value|1
end_define

begin_comment
comment|/* Incr PC	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_INCR_LINUM
value|2
end_define

begin_comment
comment|/* Incr Line #	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_INCR_LINUM_W
value|3
end_define

begin_comment
comment|/* Incr Line #	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SET_LINUM_INCR
value|4
end_define

begin_define
define|#
directive|define
name|DST_S_C_SET_LINUM_INCR_W
value|5
end_define

begin_define
define|#
directive|define
name|DST_S_C_RESET_LINUM_INCR
value|6
end_define

begin_define
define|#
directive|define
name|DST_S_C_BEG_STMT_MODE
value|7
end_define

begin_define
define|#
directive|define
name|DST_S_C_END_STMT_MODE
value|8
end_define

begin_define
define|#
directive|define
name|DST_S_C_SET_LINE_NUM
value|9
end_define

begin_comment
comment|/* Set Line #	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SET_PC
value|10
end_define

begin_define
define|#
directive|define
name|DST_S_C_SET_PC_W
value|11
end_define

begin_define
define|#
directive|define
name|DST_S_C_SET_PC_L
value|12
end_define

begin_define
define|#
directive|define
name|DST_S_C_SET_STMTNUM
value|13
end_define

begin_define
define|#
directive|define
name|DST_S_C_TERM
value|14
end_define

begin_comment
comment|/* End of lines	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_TERM_W
value|15
end_define

begin_comment
comment|/* End of lines	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SET_ABS_PC
value|16
end_define

begin_comment
comment|/* Set PC	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_DELTA_PC_L
value|17
end_define

begin_comment
comment|/* Incr PC	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_INCR_LINUM_L
value|18
end_define

begin_comment
comment|/* Incr Line #	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SET_LINUM_B
value|19
end_define

begin_comment
comment|/* Set Line #	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SET_LINUM_L
value|20
end_define

begin_comment
comment|/* Set Line #	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_TERM_L
value|21
end_define

begin_comment
comment|/* End of lines	*/
end_comment

begin_comment
comment|/* these are used with DST_S_C_SOURCE */
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SRC_DECLFILE
value|1
end_define

begin_comment
comment|/* Declare source file */
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SRC_SETFILE
value|2
end_define

begin_comment
comment|/* Set source file */
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SRC_SETREC_L
value|3
end_define

begin_comment
comment|/* Set record, longword value */
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SRC_SETREC_W
value|4
end_define

begin_comment
comment|/* Set record, word value */
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SRC_DEFLINES_W
value|10
end_define

begin_comment
comment|/* # of line, word counter */
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SRC_DEFLINES_B
value|11
end_define

begin_comment
comment|/* # of line, byte counter */
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SRC_FORMFEED
value|16
end_define

begin_comment
comment|/* ^L counts as a record */
end_comment

begin_comment
comment|/* the following are the codes for the various data types.  Anything not on  * the list is included under 'advanced_type'  */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_UCHAR
value|0x02
end_define

begin_define
define|#
directive|define
name|DBG_S_C_USINT
value|0x03
end_define

begin_define
define|#
directive|define
name|DBG_S_C_ULINT
value|0x04
end_define

begin_define
define|#
directive|define
name|DBG_S_C_UQUAD
value|0x05
end_define

begin_define
define|#
directive|define
name|DBG_S_C_SCHAR
value|0x06
end_define

begin_define
define|#
directive|define
name|DBG_S_C_SSINT
value|0x07
end_define

begin_define
define|#
directive|define
name|DBG_S_C_SLINT
value|0x08
end_define

begin_define
define|#
directive|define
name|DBG_S_C_SQUAD
value|0x09
end_define

begin_define
define|#
directive|define
name|DBG_S_C_REAL4
value|0x0a
end_define

begin_define
define|#
directive|define
name|DBG_S_C_REAL8
value|0x0b
end_define

begin_comment
comment|/* D_float double */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_COMPLX4
value|0x0c
end_define

begin_comment
comment|/* 2xF_float complex float */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_COMPLX8
value|0x0d
end_define

begin_comment
comment|/* 2xD_float complex double */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_REAL8_G
value|0x1b
end_define

begin_comment
comment|/* G_float double */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_COMPLX8_G
value|0x1d
end_define

begin_comment
comment|/* 2xG_float complex double */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_FUNCTION_ADDR
value|0x17
end_define

begin_define
define|#
directive|define
name|DBG_S_C_ADVANCED_TYPE
value|0xa3
end_define

begin_comment
comment|/*  Some of these are just for future reference.  [pr]  */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_UBITA
value|0x01
end_define

begin_comment
comment|/* unsigned, aligned bit field */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_UBITU
value|0x22
end_define

begin_comment
comment|/* unsigned, unaligned bit field */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_SBITA
value|0x29
end_define

begin_comment
comment|/* signed, aligned bit field */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_SBITU
value|0x2a
end_define

begin_comment
comment|/* signed, unaligned bit field */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_CSTRING
value|0x2e
end_define

begin_comment
comment|/* asciz ('\0' terminated) string */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_WCHAR
value|0x38
end_define

begin_comment
comment|/* wchar_t */
end_comment

begin_comment
comment|/*  These are descriptor class codes.  */
end_comment

begin_define
define|#
directive|define
name|DSC_K_CLASS_S
value|0x01
end_define

begin_comment
comment|/* static (fixed length) */
end_comment

begin_define
define|#
directive|define
name|DSC_K_CLASS_D
value|0x02
end_define

begin_comment
comment|/* dynamic string (not via malloc!) */
end_comment

begin_define
define|#
directive|define
name|DSC_K_CLASS_A
value|0x04
end_define

begin_comment
comment|/* array */
end_comment

begin_define
define|#
directive|define
name|DSC_K_CLASS_UBS
value|0x0d
end_define

begin_comment
comment|/* unaligned bit string */
end_comment

begin_comment
comment|/*  These are the codes that are used to generate the definitions of struct  *  union and enum records  */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_ENUM_ITEM
value|0xa4
end_define

begin_define
define|#
directive|define
name|DBG_S_C_ENUM_START
value|0xa5
end_define

begin_define
define|#
directive|define
name|DBG_S_C_ENUM_END
value|0xa6
end_define

begin_define
define|#
directive|define
name|DBG_S_C_STRUCT_ITEM
value|DST_K_VFLAGS_BITOFFS
end_define

begin_comment
comment|/* 0xff */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_STRUCT_START
value|0xab
end_define

begin_define
define|#
directive|define
name|DBG_S_C_STRUCT_END
value|0xac
end_define

begin_define
define|#
directive|define
name|DST_K_TYPSPEC
value|0xaf
end_define

begin_comment
comment|/* type specification */
end_comment

begin_comment
comment|/* These codes are used in the generation of the symbol definition records  */
end_comment

begin_define
define|#
directive|define
name|DST_K_VFLAGS_NOVAL
value|0x80
end_define

begin_comment
comment|/* struct definition only */
end_comment

begin_define
define|#
directive|define
name|DST_K_VFLAGS_DSC
value|0xfa
end_define

begin_comment
comment|/* descriptor used */
end_comment

begin_define
define|#
directive|define
name|DST_K_VFLAGS_TVS
value|0xfb
end_define

begin_comment
comment|/* trailing value specified */
end_comment

begin_define
define|#
directive|define
name|DST_K_VS_FOLLOWS
value|0xfd
end_define

begin_comment
comment|/* value spec follows */
end_comment

begin_define
define|#
directive|define
name|DST_K_VFLAGS_BITOFFS
value|0xff
end_define

begin_comment
comment|/* value contains bit offset */
end_comment

begin_define
define|#
directive|define
name|DST_K_VALKIND_LITERAL
value|0
end_define

begin_define
define|#
directive|define
name|DST_K_VALKIND_ADDR
value|1
end_define

begin_define
define|#
directive|define
name|DST_K_VALKIND_DESC
value|2
end_define

begin_define
define|#
directive|define
name|DST_K_VALKIND_REG
value|3
end_define

begin_define
define|#
directive|define
name|DST_K_REG_VAX_AP
value|0x0c
end_define

begin_comment
comment|/* R12 */
end_comment

begin_define
define|#
directive|define
name|DST_K_REG_VAX_FP
value|0x0d
end_define

begin_comment
comment|/* R13 */
end_comment

begin_define
define|#
directive|define
name|DST_K_REG_VAX_SP
value|0x0e
end_define

begin_comment
comment|/* R14 */
end_comment

begin_define
define|#
directive|define
name|DST_V_VALKIND
value|0
end_define

begin_comment
comment|/* offset of valkind field */
end_comment

begin_define
define|#
directive|define
name|DST_V_INDIRECT
value|2
end_define

begin_comment
comment|/* offset to indirect bit */
end_comment

begin_define
define|#
directive|define
name|DST_V_DISP
value|3
end_define

begin_comment
comment|/* offset to displacement bit */
end_comment

begin_define
define|#
directive|define
name|DST_V_REGNUM
value|4
end_define

begin_comment
comment|/* offset to register number */
end_comment

begin_define
define|#
directive|define
name|DST_M_INDIRECT
value|(1<<DST_V_INDIRECT)
end_define

begin_define
define|#
directive|define
name|DST_M_DISP
value|(1<<DST_V_DISP)
end_define

begin_define
define|#
directive|define
name|DBG_C_FUNCTION_PARAM
comment|/* 0xc9 */
define|\
value|(DST_K_VALKIND_ADDR|DST_M_DISP|(DST_K_REG_VAX_AP<<DST_V_REGNUM))
end_define

begin_define
define|#
directive|define
name|DBG_C_LOCAL_SYM
comment|/* 0xd9 */
define|\
value|(DST_K_VALKIND_ADDR|DST_M_DISP|(DST_K_REG_VAX_FP<<DST_V_REGNUM))
end_define

begin_comment
comment|/* Kinds of value specifications  */
end_comment

begin_define
define|#
directive|define
name|DST_K_VS_ALLOC_SPLIT
value|3
end_define

begin_comment
comment|/* split lifetime */
end_comment

begin_comment
comment|/* Kinds of type specifications  */
end_comment

begin_define
define|#
directive|define
name|DST_K_TS_ATOM
value|0x01
end_define

begin_comment
comment|/* atomic type specification */
end_comment

begin_define
define|#
directive|define
name|DST_K_TS_DSC
value|0x02
end_define

begin_comment
comment|/* descriptor type spec */
end_comment

begin_define
define|#
directive|define
name|DST_K_TS_IND
value|0x03
end_define

begin_comment
comment|/* indirect type specification */
end_comment

begin_define
define|#
directive|define
name|DST_K_TS_TPTR
value|0x04
end_define

begin_comment
comment|/* typed pointer type spec */
end_comment

begin_define
define|#
directive|define
name|DST_K_TS_PTR
value|0x05
end_define

begin_comment
comment|/* pointer type spec */
end_comment

begin_define
define|#
directive|define
name|DST_K_TS_ARRAY
value|0x07
end_define

begin_comment
comment|/* array type spec */
end_comment

begin_define
define|#
directive|define
name|DST_K_TS_NOV_LENG
value|0x0e
end_define

begin_comment
comment|/* novel length type spec */
end_comment

begin_comment
comment|/*  These are the codes that are used in the suffix records to determine the  *  actual data type  */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_BASIC
value|DST_K_TS_ATOM
end_define

begin_define
define|#
directive|define
name|DBG_S_C_BASIC_ARRAY
value|DST_K_TS_DSC
end_define

begin_define
define|#
directive|define
name|DBG_S_C_STRUCT
value|DST_K_TS_IND
end_define

begin_define
define|#
directive|define
name|DBG_S_C_POINTER
value|DST_K_TS_TPTR
end_define

begin_define
define|#
directive|define
name|DBG_S_C_VOID
value|DST_K_TS_PTR
end_define

begin_define
define|#
directive|define
name|DBG_S_C_COMPLEX_ARRAY
value|DST_K_TS_ARRAY
end_define

begin_comment
comment|/* VMS Module header record (EMH) definitions.  */
end_comment

begin_define
define|#
directive|define
name|MHD_S_C_MHD
value|0
end_define

begin_define
define|#
directive|define
name|MHD_S_C_LNM
value|1
end_define

begin_define
define|#
directive|define
name|MHD_S_C_SRC
value|2
end_define

begin_define
define|#
directive|define
name|MHD_S_C_TTL
value|3
end_define

begin_define
define|#
directive|define
name|MHD_S_C_CPR
value|4
end_define

begin_define
define|#
directive|define
name|MHD_S_C_MTC
value|5
end_define

begin_define
define|#
directive|define
name|MHD_S_C_GTX
value|6
end_define

begin_define
define|#
directive|define
name|MHD_S_C_MAXHDRTYP
value|6
end_define

begin_define
define|#
directive|define
name|EMH_S_C_MHD
value|0
end_define

begin_comment
comment|/* Main header record		*/
end_comment

begin_define
define|#
directive|define
name|EMH_S_C_LNM
value|1
end_define

begin_comment
comment|/* Language name and version	*/
end_comment

begin_define
define|#
directive|define
name|EMH_S_C_SRC
value|2
end_define

begin_comment
comment|/* Source file specification	*/
end_comment

begin_define
define|#
directive|define
name|EMH_S_C_TTL
value|3
end_define

begin_comment
comment|/* Title text of module		*/
end_comment

begin_define
define|#
directive|define
name|EMH_S_C_CPR
value|4
end_define

begin_comment
comment|/* Copyright notice		*/
end_comment

begin_define
define|#
directive|define
name|EMH_S_C_MTC
value|5
end_define

begin_comment
comment|/* Maintenance status		*/
end_comment

begin_define
define|#
directive|define
name|EMH_S_C_GTX
value|6
end_define

begin_comment
comment|/* General text			*/
end_comment

begin_define
define|#
directive|define
name|EMH_S_C_MAXHDRTYP
value|6
end_define

begin_comment
comment|/* Maximum allowable type	*/
end_comment

begin_comment
comment|/* vms.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|asymbol
modifier|*
name|_bfd_vms_make_empty_symbol
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vms-gsd.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_bfd_vms_slurp_gsd
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|int
name|objtype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_bfd_vms_write_gsd
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|int
name|objtype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vms-mhd.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_bfd_vms_slurp_hdr
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|int
name|objtype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_bfd_vms_write_hdr
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|int
name|objtype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_bfd_vms_slurp_eom
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|int
name|objtype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_bfd_vms_write_eom
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|int
name|objtype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vms-tir.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_bfd_vms_slurp_tir
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|int
name|objtype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_bfd_vms_slurp_dbg
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|int
name|objtype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_bfd_vms_slurp_tbt
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|int
name|objtype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_bfd_vms_slurp_lnk
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|int
name|objtype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_bfd_vms_write_tir
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|int
name|objtype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_bfd_vms_write_tbt
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|int
name|objtype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_bfd_vms_write_dbg
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|int
name|objtype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The r_type field in a reloc is one of the following values.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_R_IGNORE
value|0
end_define

begin_define
define|#
directive|define
name|ALPHA_R_REFQUAD
value|1
end_define

begin_define
define|#
directive|define
name|ALPHA_R_BRADDR
value|2
end_define

begin_define
define|#
directive|define
name|ALPHA_R_HINT
value|3
end_define

begin_define
define|#
directive|define
name|ALPHA_R_SREL16
value|4
end_define

begin_define
define|#
directive|define
name|ALPHA_R_SREL32
value|5
end_define

begin_define
define|#
directive|define
name|ALPHA_R_SREL64
value|6
end_define

begin_define
define|#
directive|define
name|ALPHA_R_OP_PUSH
value|7
end_define

begin_define
define|#
directive|define
name|ALPHA_R_OP_STORE
value|8
end_define

begin_define
define|#
directive|define
name|ALPHA_R_OP_PSUB
value|9
end_define

begin_define
define|#
directive|define
name|ALPHA_R_OP_PRSHIFT
value|10
end_define

begin_define
define|#
directive|define
name|ALPHA_R_LINKAGE
value|11
end_define

begin_define
define|#
directive|define
name|ALPHA_R_REFLONG
value|12
end_define

begin_define
define|#
directive|define
name|ALPHA_R_CODEADDR
value|13
end_define

begin_comment
comment|/* Object language definitions.  */
end_comment

begin_define
define|#
directive|define
name|OBJ_S_C_HDR
value|0
end_define

begin_comment
comment|/*VAX module header record		*/
end_comment

begin_define
define|#
directive|define
name|OBJ_S_C_GSD
value|1
end_define

begin_comment
comment|/*VAX global symbol definition record	*/
end_comment

begin_define
define|#
directive|define
name|OBJ_S_C_TIR
value|2
end_define

begin_comment
comment|/*VAX text information record		*/
end_comment

begin_define
define|#
directive|define
name|OBJ_S_C_EOM
value|3
end_define

begin_comment
comment|/*VAX end of module record		*/
end_comment

begin_define
define|#
directive|define
name|OBJ_S_C_DBG
value|4
end_define

begin_comment
comment|/*VAX Debugger information record	*/
end_comment

begin_define
define|#
directive|define
name|OBJ_S_C_TBT
value|5
end_define

begin_comment
comment|/*VAX Traceback information record	*/
end_comment

begin_define
define|#
directive|define
name|OBJ_S_C_LNK
value|6
end_define

begin_comment
comment|/*VAX linker options record		*/
end_comment

begin_define
define|#
directive|define
name|OBJ_S_C_EOMW
value|7
end_define

begin_comment
comment|/*VAX end of module word-psect record	*/
end_comment

begin_define
define|#
directive|define
name|OBJ_S_C_MAXRECTYP
value|7
end_define

begin_comment
comment|/*VAX Last assigned record type		*/
end_comment

begin_define
define|#
directive|define
name|EOBJ_S_C_EMH
value|8
end_define

begin_comment
comment|/*EVAX module header record		*/
end_comment

begin_define
define|#
directive|define
name|EOBJ_S_C_EEOM
value|9
end_define

begin_comment
comment|/*EVAX end of module record		*/
end_comment

begin_define
define|#
directive|define
name|EOBJ_S_C_EGSD
value|10
end_define

begin_comment
comment|/*EVAX global symbol definition record  */
end_comment

begin_define
define|#
directive|define
name|EOBJ_S_C_ETIR
value|11
end_define

begin_comment
comment|/*EVAX text information record		*/
end_comment

begin_define
define|#
directive|define
name|EOBJ_S_C_EDBG
value|12
end_define

begin_comment
comment|/*EVAX Debugger information record	*/
end_comment

begin_define
define|#
directive|define
name|EOBJ_S_C_ETBT
value|13
end_define

begin_comment
comment|/*EVAX Traceback information record	*/
end_comment

begin_define
define|#
directive|define
name|EOBJ_S_C_MAXRECTYP
value|13
end_define

begin_comment
comment|/*EVAX Last assigned record type	*/
end_comment

begin_define
define|#
directive|define
name|OBJ_S_K_SUBTYP
value|1
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_SUBTYP
value|1
end_define

begin_define
define|#
directive|define
name|EOBJ_S_K_SUBTYP
value|4
end_define

begin_define
define|#
directive|define
name|EOBJ_S_C_SUBTYP
value|4
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_MAXRECSIZ
value|2048
end_define

begin_comment
comment|/*Maximum legal record size         */
end_comment

begin_define
define|#
directive|define
name|EOBJ_S_C_MAXRECSIZ
value|8192
end_define

begin_comment
comment|/*Maximum legal record size         */
end_comment

begin_define
define|#
directive|define
name|OBJ_S_C_STRLVL
value|0
end_define

begin_comment
comment|/*Structure level                   */
end_comment

begin_define
define|#
directive|define
name|EOBJ_S_C_STRLVL
value|2
end_define

begin_comment
comment|/*Structure level                   */
end_comment

begin_define
define|#
directive|define
name|OBJ_S_C_SYMSIZ
value|31
end_define

begin_comment
comment|/*Maximum symbol length		*/
end_comment

begin_define
define|#
directive|define
name|EOBJ_S_C_SYMSIZ
value|64
end_define

begin_comment
comment|/*Maximum symbol length		*/
end_comment

begin_define
define|#
directive|define
name|EOBJ_S_C_SECSIZ
value|31
end_define

begin_comment
comment|/*Maximum section name length		*/
end_comment

begin_define
define|#
directive|define
name|OBJ_S_C_STOREPLIM
value|-1
end_define

begin_comment
comment|/*Maximum repeat count on store commands  */
end_comment

begin_define
define|#
directive|define
name|EOBJ_S_C_STOREPLIM
value|-1
end_define

begin_comment
comment|/*Maximum repeat count on store commands  */
end_comment

begin_define
define|#
directive|define
name|OBJ_S_C_PSCALILIM
value|9
end_define

begin_comment
comment|/*Maximum p-sect alignment          */
end_comment

begin_define
define|#
directive|define
name|EOBJ_S_C_PSCALILIM
value|16
end_define

begin_comment
comment|/*Maximum p-sect alignment          */
end_comment

begin_define
define|#
directive|define
name|EVAX_OFFSET
value|256
end_define

begin_comment
comment|/*type offset for EVAX codes in switch  */
end_comment

begin_comment
comment|/* Miscellaneous definitions.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|uquad
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|long
name|uquad
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAX_OUTREC_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|MIN_OUTREC_LUFT
value|64
end_define

begin_typedef
typedef|typedef
struct|struct
name|_vms_section
block|{
name|unsigned
name|char
modifier|*
name|contents
decl_stmt|;
name|bfd_vma
name|offset
decl_stmt|;
name|bfd_size_type
name|size
decl_stmt|;
name|struct
name|_vms_section
modifier|*
name|next
decl_stmt|;
block|}
name|vms_section
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|vms_section
modifier|*
name|_bfd_get_vms_section
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|int
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
name|_vms_reloc
block|{
name|struct
name|_vms_reloc
modifier|*
name|next
decl_stmt|;
name|arelent
modifier|*
name|reloc
decl_stmt|;
name|asection
modifier|*
name|section
decl_stmt|;
block|}
name|vms_reloc
typedef|;
end_typedef

begin_comment
comment|/* vms module header  */
end_comment

begin_struct
struct|struct
name|hdr_struc
block|{
name|int
name|hdr_b_strlvl
decl_stmt|;
name|long
name|hdr_l_arch1
decl_stmt|;
name|long
name|hdr_l_arch2
decl_stmt|;
name|long
name|hdr_l_recsiz
decl_stmt|;
name|char
modifier|*
name|hdr_t_name
decl_stmt|;
name|char
modifier|*
name|hdr_t_version
decl_stmt|;
name|char
modifier|*
name|hdr_t_date
decl_stmt|;
name|char
modifier|*
name|hdr_c_lnm
decl_stmt|;
name|char
modifier|*
name|hdr_c_src
decl_stmt|;
name|char
modifier|*
name|hdr_c_ttl
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* vms end of module  */
end_comment

begin_struct
struct|struct
name|eom_struc
block|{
name|long
name|eom_l_total_lps
decl_stmt|;
name|unsigned
name|char
name|eom_b_comcod
decl_stmt|;
name|bfd_boolean
name|eom_has_transfer
decl_stmt|;
name|unsigned
name|char
name|eom_b_tfrflg
decl_stmt|;
name|long
name|eom_l_psindx
decl_stmt|;
name|long
name|eom_l_tfradr
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|file_format_enum
block|{
name|FF_UNKNOWN
block|,
name|FF_FOREIGN
block|,
name|FF_NATIVE
block|,
name|FF_VAX
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|vms_symbol_struct
block|{
name|struct
name|bfd_hash_entry
name|bfd_hash
decl_stmt|;
name|asymbol
modifier|*
name|symbol
decl_stmt|;
block|}
name|vms_symbol_entry
typedef|;
end_typedef

begin_comment
comment|/* stack value for push/pop commands  */
end_comment

begin_struct
struct|struct
name|stack_struct
block|{
name|uquad
name|value
decl_stmt|;
name|int
name|psect
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|STACKSIZE
value|8192
end_define

begin_comment
comment|/* location stack definitions for CTL_DFLOC, CTL_STLOC, and CTL_STKDL  */
end_comment

begin_struct
struct|struct
name|location_struct
block|{
name|unsigned
name|long
name|value
decl_stmt|;
name|int
name|psect
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LOCATION_SAVE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|VMS_SECTION_COUNT
value|1024
end_define

begin_struct
struct|struct
name|vms_private_data_struct
block|{
name|int
name|is_vax
decl_stmt|;
name|bfd_boolean
name|fixup_done
decl_stmt|;
comment|/* Flag to indicate if all 					   section pointers and PRIV(sections) 					   are set up correctly  */
name|unsigned
name|char
modifier|*
name|vms_buf
decl_stmt|;
comment|/* buffer to record  */
name|int
name|buf_size
decl_stmt|;
comment|/* max size of buffer  */
name|unsigned
name|char
modifier|*
name|vms_rec
decl_stmt|;
comment|/* actual record ptr  */
name|int
name|rec_length
decl_stmt|;
comment|/* remaining record length  */
name|int
name|rec_size
decl_stmt|;
comment|/* actual record size  */
name|int
name|rec_type
decl_stmt|;
comment|/* actual record type  */
name|enum
name|file_format_enum
name|file_format
decl_stmt|;
name|struct
name|hdr_struc
name|hdr_data
decl_stmt|;
comment|/* data from HDR/EMH record  */
name|struct
name|eom_struc
name|eom_data
decl_stmt|;
comment|/* data from EOM/EEOM record  */
name|unsigned
name|int
name|section_count
decl_stmt|;
comment|/* # of sections in following array  */
name|asection
modifier|*
modifier|*
name|sections
decl_stmt|;
comment|/* array of GSD/EGSD sections  */
name|int
name|gsd_sym_count
decl_stmt|;
comment|/* # of GSD/EGSD symbols  */
name|asymbol
modifier|*
modifier|*
name|symbols
decl_stmt|;
comment|/* vector of GSD/EGSD symbols  */
name|struct
name|proc_value
modifier|*
name|procedure
decl_stmt|;
name|struct
name|stack_struct
modifier|*
name|stack
decl_stmt|;
name|int
name|stackptr
decl_stmt|;
name|vms_section
modifier|*
name|vms_section_table
index|[
name|VMS_SECTION_COUNT
index|]
decl_stmt|;
name|struct
name|bfd_hash_table
modifier|*
name|vms_symbol_table
decl_stmt|;
name|struct
name|bfd_symbol
modifier|*
modifier|*
name|symcache
decl_stmt|;
name|int
name|symnum
decl_stmt|;
name|struct
name|location_struct
modifier|*
name|location_stack
decl_stmt|;
name|asection
modifier|*
name|image_section
decl_stmt|;
comment|/* section for image_ptr  */
name|unsigned
name|char
modifier|*
name|image_ptr
decl_stmt|;
comment|/* a pointer to section->contents */
name|unsigned
name|char
name|pdsc
index|[
literal|8
index|]
decl_stmt|;
comment|/* procedure descriptor */
comment|/* Output routine storage  */
name|unsigned
name|char
modifier|*
name|output_buf
decl_stmt|;
comment|/* output data  */
name|int
name|push_level
decl_stmt|;
name|int
name|pushed_size
decl_stmt|;
name|int
name|length_pos
decl_stmt|;
name|int
name|output_size
decl_stmt|;
name|int
name|output_alignment
decl_stmt|;
comment|/* linkage index counter    used by conditional store commands (ETIR_S_C_STC_)  */
name|int
name|vms_linkage_index
decl_stmt|;
comment|/* see tc-alpha.c of gas for a description.  */
name|int
name|flag_hash_long_names
decl_stmt|;
comment|/* -+, hash instead of truncate */
name|int
name|flag_show_after_trunc
decl_stmt|;
comment|/* -H, show hashing/truncation */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PRIV
parameter_list|(
name|name
parameter_list|)
value|((struct vms_private_data_struct *)abfd->tdata.any)->name
end_define

begin_define
define|#
directive|define
name|SECTION_NAME_TEMPLATE
value|"__SEC__%d"
end_define

begin_if
if|#
directive|if
name|VMS_DEBUG
end_if

begin_decl_stmt
specifier|extern
name|void
name|_bfd_vms_debug
name|PARAMS
argument_list|(
operator|(
name|int
name|level
operator|,
name|char
operator|*
name|format
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_hexdump
name|PARAMS
argument_list|(
operator|(
name|int
name|level
operator|,
name|unsigned
name|char
operator|*
name|ptr
operator|,
name|int
name|size
operator|,
name|int
name|offset
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|vms_debug
value|_bfd_vms_debug
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|bfd_hash_entry
modifier|*
name|_bfd_vms_hash_newfunc
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_hash_entry
operator|*
name|entry
operator|,
expr|struct
name|bfd_hash_table
operator|*
name|table
operator|,
specifier|const
name|char
operator|*
name|string
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_vms_get_header_values
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|unsigned
name|char
operator|*
name|buf
operator|,
name|int
operator|*
name|type
operator|,
name|int
operator|*
name|length
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_bfd_vms_get_record
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_bfd_vms_next_record
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_bfd_vms_save_sized_string
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|char
operator|*
name|str
operator|,
name|int
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_bfd_vms_save_counted_string
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|char
operator|*
name|ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_vms_push
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|uquad
name|val
operator|,
name|int
name|psect
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uquad
name|_bfd_vms_pop
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|int
operator|*
name|psect
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|_bfd_save_vms_section
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|asection
operator|*
name|section
operator|,
specifier|const
name|PTR
name|data
operator|,
name|file_ptr
name|offset
operator|,
name|bfd_size_type
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_vms_output_begin
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|int
name|rectype
operator|,
name|int
name|rechead
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_vms_output_alignment
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|int
name|alignto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_vms_output_push
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_vms_output_pop
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_vms_output_flush
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_vms_output_end
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_bfd_vms_output_check
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|int
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_vms_output_byte
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|unsigned
name|int
name|value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_vms_output_short
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|unsigned
name|int
name|value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_vms_output_long
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|unsigned
name|long
name|value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_vms_output_quad
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|uquad
name|value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_vms_output_counted
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|char
operator|*
name|value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_vms_output_dump
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|unsigned
name|char
operator|*
name|data
operator|,
name|int
name|length
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_vms_output_fill
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|int
name|value
operator|,
name|int
name|length
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_bfd_vms_length_hash_symbol
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
specifier|const
name|char
operator|*
name|in
operator|,
name|int
name|maxlen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vms_symbol_entry
modifier|*
name|_bfd_vms_enter_symbol
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS_H */
end_comment

end_unit

