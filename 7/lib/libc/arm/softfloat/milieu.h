begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: milieu.h,v 1.1 2000/12/29 20:13:54 bjh21 Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* ===============================================================================  This C header file is part of the SoftFloat IEC/IEEE Floating-point Arithmetic Package, Release 2a.  Written by John R. Hauser.  This work was made possible in part by the International Computer Science Institute, located at Suite 600, 1947 Center Street, Berkeley, California 94704.  Funding was partially provided by the National Science Foundation under grant MIP-9311980.  The original version of this code was written as part of a project to build a fixed-point vector processor in collaboration with the University of California at Berkeley, overseen by Profs. Nelson Morgan and John Wawrzynek.  More information is available through the Web page `http://HTTP.CS.Berkeley.EDU/~jhauser/ arithmetic/SoftFloat.html'.  THIS SOFTWARE IS DISTRIBUTED AS IS, FOR FREE.  Although reasonable effort has been made to avoid it, THIS SOFTWARE MAY CONTAIN FAULTS THAT WILL AT TIMES RESULT IN INCORRECT BEHAVIOR.  USE OF THIS SOFTWARE IS RESTRICTED TO PERSONS AND ORGANIZATIONS WHO CAN AND WILL TAKE FULL RESPONSIBILITY FOR ANY AND ALL LOSSES, COSTS, OR OTHER PROBLEMS ARISING FROM ITS USE.  Derivative works are acceptable, even for commercial purposes, so long as (1) they include prominent notice that the work is derivative, and (2) they include prominent notice akin to these four paragraphs for those parts of this code that are retained.  =============================================================================== */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------------- Include common integer types and flags. ------------------------------------------------------------------------------- */
end_comment

begin_include
include|#
directive|include
file|"arm-gcc.h"
end_include

begin_comment
comment|/* ------------------------------------------------------------------------------- Symbolic Boolean literals. ------------------------------------------------------------------------------- */
end_comment

begin_enum
enum|enum
block|{
name|FALSE
init|=
literal|0
block|,
name|TRUE
init|=
literal|1
block|}
enum|;
end_enum

end_unit

