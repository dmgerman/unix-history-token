begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_comment
comment|/* static	char sccsid[] = "@(#)piwhoami.h 1.2 %G%"; */
end_comment

begin_comment
comment|/*  *	am i generating an obj file (OBJ),  *	postfix binary input to the 2nd pass of the portable c compiler (PC),  *	or pTrees (PTREE)?  */
end_comment

begin_define
define|#
directive|define
name|OBJ
end_define

begin_undef
undef|#
directive|undef
name|PC
end_undef

begin_undef
undef|#
directive|undef
name|PTREE
end_undef

begin_comment
comment|/*  *	am i the vax or the pdp11 version  */
end_comment

begin_define
define|#
directive|define
name|VAX
end_define

begin_undef
undef|#
directive|undef
name|PDP11
end_undef

begin_define
define|#
directive|define
name|DEC11
end_define

begin_comment
comment|/*  *	am i pi or pxp?  */
end_comment

begin_define
define|#
directive|define
name|PI
end_define

begin_undef
undef|#
directive|undef
name|PXP
end_undef

begin_comment
comment|/*  *	am i both passes, or am i only one of the two passes pi0 or pi1?  */
end_comment

begin_define
define|#
directive|define
name|PI01
end_define

begin_undef
undef|#
directive|undef
name|PI0
end_undef

begin_undef
undef|#
directive|undef
name|PI1
end_undef

end_unit

