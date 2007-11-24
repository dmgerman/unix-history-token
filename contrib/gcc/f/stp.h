begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stp.h -- Private #include File (module.h template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       stp.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_STP_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_STP_H
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_enum
enum|enum
name|_ffestp_acceptix_
block|{
name|FFESTP_acceptixFORMAT
block|,
name|FFESTP_acceptix
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffestp_acceptix_
name|ffestpAcceptIx
typedef|;
end_typedef

begin_enum
enum|enum
name|_ffestp_attrib_
block|{
if|#
directive|if
name|FFESTR_F90
name|FFESTP_attribALLOCATABLE
block|,
endif|#
directive|endif
name|FFESTP_attribDIMENSION
block|,
name|FFESTP_attribEXTERNAL
block|,
if|#
directive|if
name|FFESTR_F90
name|FFESTP_attribINTENT
block|,
endif|#
directive|endif
name|FFESTP_attribINTRINSIC
block|,
if|#
directive|if
name|FFESTR_F90
name|FFESTP_attribOPTIONAL
block|,
endif|#
directive|endif
name|FFESTP_attribPARAMETER
block|,
if|#
directive|if
name|FFESTR_F90
name|FFESTP_attribPOINTER
block|,
endif|#
directive|endif
if|#
directive|if
name|FFESTR_F90
name|FFESTP_attribPRIVATE
block|,
name|FFESTP_attribPUBLIC
block|,
endif|#
directive|endif
name|FFESTP_attribSAVE
block|,
if|#
directive|if
name|FFESTR_F90
name|FFESTP_attribTARGET
block|,
endif|#
directive|endif
name|FFESTP_attrib
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffestp_attrib_
name|ffestpAttrib
typedef|;
end_typedef

begin_enum
enum|enum
name|_ffestp_beruix_
block|{
name|FFESTP_beruixERR
block|,
name|FFESTP_beruixIOSTAT
block|,
name|FFESTP_beruixUNIT
block|,
name|FFESTP_beruix
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffestp_beruix_
name|ffestpBeruIx
typedef|;
end_typedef

begin_enum
enum|enum
name|_ffestp_closeix_
block|{
name|FFESTP_closeixERR
block|,
name|FFESTP_closeixIOSTAT
block|,
name|FFESTP_closeixSTATUS
block|,
name|FFESTP_closeixUNIT
block|,
name|FFESTP_closeix
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffestp_closeix_
name|ffestpCloseIx
typedef|;
end_typedef

begin_enum
enum|enum
name|_ffestp_deleteix_
block|{
name|FFESTP_deleteixERR
block|,
name|FFESTP_deleteixIOSTAT
block|,
name|FFESTP_deleteixREC
block|,
name|FFESTP_deleteixUNIT
block|,
name|FFESTP_deleteix
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffestp_deleteix_
name|ffestpDeleteIx
typedef|;
end_typedef

begin_enum
enum|enum
name|_ffestp_findix_
block|{
name|FFESTP_findixERR
block|,
name|FFESTP_findixIOSTAT
block|,
name|FFESTP_findixREC
block|,
name|FFESTP_findixUNIT
block|,
name|FFESTP_findix
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffestp_findix_
name|ffestpFindIx
typedef|;
end_typedef

begin_enum
enum|enum
name|_ffestp_inquireix_
block|{
name|FFESTP_inquireixACCESS
block|,
name|FFESTP_inquireixACTION
block|,
name|FFESTP_inquireixBLANK
block|,
name|FFESTP_inquireixCARRIAGECONTROL
block|,
name|FFESTP_inquireixDEFAULTFILE
block|,
name|FFESTP_inquireixDELIM
block|,
name|FFESTP_inquireixDIRECT
block|,
name|FFESTP_inquireixERR
block|,
name|FFESTP_inquireixEXIST
block|,
name|FFESTP_inquireixFILE
block|,
name|FFESTP_inquireixFORM
block|,
name|FFESTP_inquireixFORMATTED
block|,
name|FFESTP_inquireixIOLENGTH
block|,
name|FFESTP_inquireixIOSTAT
block|,
name|FFESTP_inquireixKEYED
block|,
name|FFESTP_inquireixNAME
block|,
name|FFESTP_inquireixNAMED
block|,
name|FFESTP_inquireixNEXTREC
block|,
name|FFESTP_inquireixNUMBER
block|,
name|FFESTP_inquireixOPENED
block|,
name|FFESTP_inquireixORGANIZATION
block|,
name|FFESTP_inquireixPAD
block|,
name|FFESTP_inquireixPOSITION
block|,
name|FFESTP_inquireixREAD
block|,
name|FFESTP_inquireixREADWRITE
block|,
name|FFESTP_inquireixRECL
block|,
name|FFESTP_inquireixRECORDTYPE
block|,
name|FFESTP_inquireixSEQUENTIAL
block|,
name|FFESTP_inquireixUNFORMATTED
block|,
name|FFESTP_inquireixUNIT
block|,
name|FFESTP_inquireixWRITE
block|,
name|FFESTP_inquireix
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffestp_inquireix_
name|ffestpInquireIx
typedef|;
end_typedef

begin_enum
enum|enum
name|_ffestp_openix_
block|{
name|FFESTP_openixACCESS
block|,
name|FFESTP_openixACTION
block|,
name|FFESTP_openixASSOCIATEVARIABLE
block|,
name|FFESTP_openixBLANK
block|,
name|FFESTP_openixBLOCKSIZE
block|,
name|FFESTP_openixBUFFERCOUNT
block|,
name|FFESTP_openixCARRIAGECONTROL
block|,
name|FFESTP_openixDEFAULTFILE
block|,
name|FFESTP_openixDELIM
block|,
name|FFESTP_openixDISPOSE
block|,
name|FFESTP_openixERR
block|,
name|FFESTP_openixEXTENDSIZE
block|,
name|FFESTP_openixFILE
block|,
name|FFESTP_openixFORM
block|,
name|FFESTP_openixINITIALSIZE
block|,
name|FFESTP_openixIOSTAT
block|,
name|FFESTP_openixKEY
block|,
name|FFESTP_openixMAXREC
block|,
name|FFESTP_openixNOSPANBLOCKS
block|,
name|FFESTP_openixORGANIZATION
block|,
name|FFESTP_openixPAD
block|,
name|FFESTP_openixPOSITION
block|,
name|FFESTP_openixREADONLY
block|,
name|FFESTP_openixRECL
block|,
name|FFESTP_openixRECORDTYPE
block|,
name|FFESTP_openixSHARED
block|,
name|FFESTP_openixSTATUS
block|,
name|FFESTP_openixUNIT
block|,
name|FFESTP_openixUSEROPEN
block|,
name|FFESTP_openix
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffestp_openix_
name|ffestpOpenIx
typedef|;
end_typedef

begin_enum
enum|enum
name|_ffestp_printix_
block|{
name|FFESTP_printixFORMAT
block|,
name|FFESTP_printix
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffestp_printix_
name|ffestpPrintIx
typedef|;
end_typedef

begin_enum
enum|enum
name|_ffestp_readix_
block|{
name|FFESTP_readixADVANCE
block|,
name|FFESTP_readixEND
block|,
name|FFESTP_readixEOR
block|,
name|FFESTP_readixERR
block|,
name|FFESTP_readixFORMAT
block|,
comment|/* Or NAMELIST (use expr info to 				   distinguish). */
name|FFESTP_readixIOSTAT
block|,
name|FFESTP_readixKEYEQ
block|,
name|FFESTP_readixKEYGE
block|,
name|FFESTP_readixKEYGT
block|,
name|FFESTP_readixKEYID
block|,
name|FFESTP_readixNULLS
block|,
name|FFESTP_readixREC
block|,
name|FFESTP_readixSIZE
block|,
name|FFESTP_readixUNIT
block|,
name|FFESTP_readix
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffestp_readix_
name|ffestpReadIx
typedef|;
end_typedef

begin_enum
enum|enum
name|_ffestp_rewriteix_
block|{
name|FFESTP_rewriteixERR
block|,
name|FFESTP_rewriteixFMT
block|,
name|FFESTP_rewriteixIOSTAT
block|,
name|FFESTP_rewriteixUNIT
block|,
name|FFESTP_rewriteix
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffestp_rewriteix_
name|ffestpRewriteIx
typedef|;
end_typedef

begin_enum
enum|enum
name|_ffestp_typeix_
block|{
name|FFESTP_typeixFORMAT
block|,
name|FFESTP_typeix
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffestp_typeix_
name|ffestpTypeIx
typedef|;
end_typedef

begin_enum
enum|enum
name|_ffestp_vxtcodeix_
block|{
name|FFESTP_vxtcodeixB
block|,
name|FFESTP_vxtcodeixC
block|,
name|FFESTP_vxtcodeixERR
block|,
name|FFESTP_vxtcodeixF
block|,
name|FFESTP_vxtcodeixIOSTAT
block|,
name|FFESTP_vxtcodeix
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffestp_vxtcodeix_
name|ffestpVxtcodeIx
typedef|;
end_typedef

begin_enum
enum|enum
name|_ffestp_writeix_
block|{
name|FFESTP_writeixADVANCE
block|,
name|FFESTP_writeixEOR
block|,
name|FFESTP_writeixERR
block|,
name|FFESTP_writeixFORMAT
block|,
comment|/* Or NAMELIST (use expr info to 				   distinguish). */
name|FFESTP_writeixIOSTAT
block|,
name|FFESTP_writeixREC
block|,
name|FFESTP_writeixUNIT
block|,
name|FFESTP_writeix
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffestp_writeix_
name|ffestpWriteIx
typedef|;
end_typedef

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_enum
enum|enum
name|_ffestp_definedoperator_
block|{
name|FFESTP_definedoperatorNone
block|,
comment|/* INTERFACE generic-name. */
name|FFESTP_definedoperatorOPERATOR
block|,
comment|/* INTERFACE 					   OPERATOR(defined-operator). */
name|FFESTP_definedoperatorASSIGNMENT
block|,
comment|/* INTERFACE ASSIGNMENT(=). */
name|FFESTP_definedoperatorPOWER
block|,
name|FFESTP_definedoperatorMULT
block|,
name|FFESTP_definedoperatorADD
block|,
name|FFESTP_definedoperatorCONCAT
block|,
name|FFESTP_definedoperatorDIVIDE
block|,
name|FFESTP_definedoperatorSUBTRACT
block|,
name|FFESTP_definedoperatorNOT
block|,
name|FFESTP_definedoperatorAND
block|,
name|FFESTP_definedoperatorOR
block|,
name|FFESTP_definedoperatorEQV
block|,
name|FFESTP_definedoperatorNEQV
block|,
name|FFESTP_definedoperatorEQ
block|,
name|FFESTP_definedoperatorNE
block|,
name|FFESTP_definedoperatorLT
block|,
name|FFESTP_definedoperatorLE
block|,
name|FFESTP_definedoperatorGT
block|,
name|FFESTP_definedoperatorGE
block|,
name|FFESTP_definedoperator
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffestp_definedoperator_
name|ffestpDefinedOperator
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|_ffestp_dimtype_
block|{
name|FFESTP_dimtypeNONE
block|,
name|FFESTP_dimtypeKNOWN
block|,
comment|/* Known-bounds dimension list. */
name|FFESTP_dimtypeADJUSTABLE
block|,
comment|/* Adjustable dimension list. */
name|FFESTP_dimtypeASSUMED
block|,
comment|/* Assumed dimension list (known except for 				   last). */
name|FFESTP_dimtypeADJUSTABLEASSUMED
block|,
comment|/* Both. */
name|FFESTP_dimtype
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffestp_dimtype_
name|ffestpDimtype
typedef|;
end_typedef

begin_enum
enum|enum
name|_ffestp_formattype_
block|{
name|FFESTP_formattypeNone
block|,
name|FFESTP_formattypeI
block|,
name|FFESTP_formattypeB
block|,
name|FFESTP_formattypeO
block|,
name|FFESTP_formattypeZ
block|,
name|FFESTP_formattypeF
block|,
name|FFESTP_formattypeE
block|,
name|FFESTP_formattypeEN
block|,
name|FFESTP_formattypeG
block|,
name|FFESTP_formattypeL
block|,
name|FFESTP_formattypeA
block|,
name|FFESTP_formattypeD
block|,
name|FFESTP_formattypeQ
block|,
name|FFESTP_formattypeDOLLAR
block|,
comment|/* $ (V-extension). */
name|FFESTP_formattypeP
block|,
name|FFESTP_formattypeT
block|,
name|FFESTP_formattypeTL
block|,
name|FFESTP_formattypeTR
block|,
name|FFESTP_formattypeX
block|,
name|FFESTP_formattypeS
block|,
name|FFESTP_formattypeSP
block|,
name|FFESTP_formattypeSS
block|,
name|FFESTP_formattypeBN
block|,
name|FFESTP_formattypeBZ
block|,
name|FFESTP_formattypeH
block|,
comment|/* Hollerith, used only for error-reporting. */
name|FFESTP_formattypeSLASH
block|,
name|FFESTP_formattypeCOLON
block|,
name|FFESTP_formattypeR1016
block|,
comment|/* char-literal-constant or cHchars. */
name|FFESTP_formattypeFORMAT
block|,
comment|/* [r](format-item-list). */
name|FFESTP_formattype
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffestp_formattype_
name|ffestpFormatType
typedef|;
end_typedef

begin_enum
enum|enum
name|_ffestp_type_
block|{
name|FFESTP_typeNone
block|,
name|FFESTP_typeINTEGER
block|,
name|FFESTP_typeREAL
block|,
name|FFESTP_typeCOMPLEX
block|,
name|FFESTP_typeLOGICAL
block|,
name|FFESTP_typeCHARACTER
block|,
name|FFESTP_typeDBLPRCSN
block|,
name|FFESTP_typeDBLCMPLX
block|,
name|FFESTP_typeBYTE
block|,
name|FFESTP_typeWORD
block|,
if|#
directive|if
name|FFESTR_F90
name|FFESTP_typeTYPE
block|,
endif|#
directive|endif
name|FFESTP_type
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffestp_type_
name|ffestpType
typedef|;
end_typedef

begin_comment
comment|/* Typedefs. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_ffest_accept_stmt_
name|ffestpAcceptStmt
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffest_beru_stmt_
name|ffestpBeruStmt
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffest_close_stmt_
name|ffestpCloseStmt
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffest_delete_stmt_
name|ffestpDeleteStmt
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffestp_file
name|ffestpFile
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffest_find_stmt_
name|ffestpFindStmt
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffest_inquire_stmt_
name|ffestpInquireStmt
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffest_open_stmt_
name|ffestpOpenStmt
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffest_print_stmt_
name|ffestpPrintStmt
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffest_read_stmt_
name|ffestpReadStmt
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffest_rewrite_stmt_
name|ffestpRewriteStmt
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffest_type_stmt_
name|ffestpTypeStmt
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffest_vxtcode_stmt_
name|ffestpVxtcodeStmt
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffest_write_stmt_
name|ffestpWriteStmt
typedef|;
end_typedef

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"bld.h"
end_include

begin_include
include|#
directive|include
file|"lab.h"
end_include

begin_include
include|#
directive|include
file|"lex.h"
end_include

begin_include
include|#
directive|include
file|"stp.h"
end_include

begin_include
include|#
directive|include
file|"stt.h"
end_include

begin_comment
comment|/* Structure definitions. */
end_comment

begin_struct
struct|struct
name|_ffestp_file
block|{
name|bool
name|kw_or_val_present
decl_stmt|;
comment|/* If FALSE, all else is n/a. */
name|bool
name|kw_present
decl_stmt|;
comment|/* Indicates whether kw has a token. */
name|bool
name|value_present
decl_stmt|;
comment|/* Indicates whether value/expr are valid. */
name|bool
name|value_is_label
decl_stmt|;
comment|/* TRUE if expr has no expression, value is 				   NUMBER. */
name|ffelexToken
name|kw
decl_stmt|;
comment|/* The keyword, iff kw_or_val_present&& 				   kw_present. */
name|ffelexToken
name|value
decl_stmt|;
comment|/* The value, iff kw_or_val_present&& 				   value_present. */
union|union
block|{
name|ffebld
name|expr
decl_stmt|;
comment|/* The expr, iff kw_or_val_present&& 				   value_present&& !value_is_label. */
name|ffelab
name|label
decl_stmt|;
comment|/* The label, iff kw_or_val_present&& 				   value_present&& value_is_label. */
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_accept_stmt_
block|{
name|ffestpFile
name|accept_spec
index|[
name|FFESTP_acceptix
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_beru_stmt_
block|{
name|ffestpFile
name|beru_spec
index|[
name|FFESTP_beruix
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_close_stmt_
block|{
name|ffestpFile
name|close_spec
index|[
name|FFESTP_closeix
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_delete_stmt_
block|{
name|ffestpFile
name|delete_spec
index|[
name|FFESTP_deleteix
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_find_stmt_
block|{
name|ffestpFile
name|find_spec
index|[
name|FFESTP_findix
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_imp_list_
block|{
name|ffesttImpList
name|next
decl_stmt|;
name|ffesttImpList
name|previous
decl_stmt|;
name|ffelexToken
name|first
decl_stmt|;
name|ffelexToken
name|last
decl_stmt|;
comment|/* NULL if a single letter. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_inquire_stmt_
block|{
name|ffestpFile
name|inquire_spec
index|[
name|FFESTP_inquireix
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_open_stmt_
block|{
name|ffestpFile
name|open_spec
index|[
name|FFESTP_openix
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_print_stmt_
block|{
name|ffestpFile
name|print_spec
index|[
name|FFESTP_printix
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_read_stmt_
block|{
name|ffestpFile
name|read_spec
index|[
name|FFESTP_readix
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_rewrite_stmt_
block|{
name|ffestpFile
name|rewrite_spec
index|[
name|FFESTP_rewriteix
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_type_stmt_
block|{
name|ffestpFile
name|type_spec
index|[
name|FFESTP_typeix
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_vxtcode_stmt_
block|{
name|ffestpFile
name|vxtcode_spec
index|[
name|FFESTP_vxtcodeix
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_write_stmt_
block|{
name|ffestpFile
name|write_spec
index|[
name|FFESTP_writeix
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|_ffestp_fileu_
block|{
name|ffestpAcceptStmt
name|accept
decl_stmt|;
name|ffestpBeruStmt
name|beru
decl_stmt|;
name|ffestpCloseStmt
name|close
decl_stmt|;
name|ffestpDeleteStmt
name|delete
decl_stmt|;
name|ffestpFindStmt
name|find
decl_stmt|;
name|ffestpInquireStmt
name|inquire
decl_stmt|;
name|ffestpOpenStmt
name|open
decl_stmt|;
name|ffestpPrintStmt
name|print
decl_stmt|;
name|ffestpReadStmt
name|read
decl_stmt|;
name|ffestpRewriteStmt
name|rewrite
decl_stmt|;
name|ffestpTypeStmt
name|type
decl_stmt|;
name|ffestpVxtcodeStmt
name|vxtcode
decl_stmt|;
name|ffestpWriteStmt
name|write
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_decl_stmt
specifier|extern
name|union
name|_ffestp_fileu_
name|ffestp_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffestp_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestp_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestp_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestp_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestp_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestp_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestp_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestp_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestp_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestp_terminate_4
parameter_list|()
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_F_STP_H */
end_comment

end_unit

