begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*	Copyright (c) 1988 AT&T	*/
end_comment

begin_comment
comment|/*	  All Rights Reserved  	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STORCLASS_H
end_ifndef

begin_define
define|#
directive|define
name|_STORCLASS_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_comment
comment|/* SVr4.0 1.6 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*  *   STORAGE CLASSES  */
define|#
directive|define
name|C_EFCN
value|-1
comment|/* physical end of function */
define|#
directive|define
name|C_NULL
value|0
define|#
directive|define
name|C_AUTO
value|1
comment|/* automatic variable */
define|#
directive|define
name|C_EXT
value|2
comment|/* external symbol */
define|#
directive|define
name|C_STAT
value|3
comment|/* static */
define|#
directive|define
name|C_REG
value|4
comment|/* register variable */
define|#
directive|define
name|C_EXTDEF
value|5
comment|/* external definition */
define|#
directive|define
name|C_LABEL
value|6
comment|/* label */
define|#
directive|define
name|C_ULABEL
value|7
comment|/* undefined label */
define|#
directive|define
name|C_MOS
value|8
comment|/* member of structure */
define|#
directive|define
name|C_ARG
value|9
comment|/* function argument */
define|#
directive|define
name|C_STRTAG
value|10
comment|/* structure tag */
define|#
directive|define
name|C_MOU
value|11
comment|/* member of union */
define|#
directive|define
name|C_UNTAG
value|12
comment|/* union tag */
define|#
directive|define
name|C_TPDEF
value|13
comment|/* type definition */
define|#
directive|define
name|C_USTATIC
value|14
comment|/* undefined static */
define|#
directive|define
name|C_ENTAG
value|15
comment|/* enumeration tag */
define|#
directive|define
name|C_MOE
value|16
comment|/* member of enumeration */
define|#
directive|define
name|C_REGPARM
value|17
comment|/* register parameter */
define|#
directive|define
name|C_FIELD
value|18
comment|/* bit field */
define|#
directive|define
name|C_BLOCK
value|100
comment|/* ".bb" or ".eb" */
define|#
directive|define
name|C_FCN
value|101
comment|/* ".bf" or ".ef" */
define|#
directive|define
name|C_EOS
value|102
comment|/* end of structure */
define|#
directive|define
name|C_FILE
value|103
comment|/* file name */
comment|/*  * The following storage class is a "dummy" used only by STS  * for line number entries reformatted as symbol table entries  */
define|#
directive|define
name|C_LINE
value|104
define|#
directive|define
name|C_ALIAS
value|105
comment|/* duplicate tag */
define|#
directive|define
name|C_HIDDEN
value|106
comment|/* special storage class for external */
comment|/* symbols in dmert public libraries */
define|#
directive|define
name|C_SHADOW
value|107
comment|/* shadow symbol */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STORCLASS_H */
end_comment

end_unit

