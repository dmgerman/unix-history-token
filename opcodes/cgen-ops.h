begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Semantics ops support for CGEN-based opcode libraries.    Copyright (C) 2005 Free Software Foundation, Inc.    Contributed by Red Hat.  This file is part of the GNU opcodes library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CGEN_SEM_OPS_H
end_ifndef

begin_define
define|#
directive|define
name|CGEN_SEM_OPS_H
end_define

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SEMOPS_DEFINE_INLINE
argument_list|)
end_if

begin_define
define|#
directive|define
name|SEMOPS_DEFINE_INLINE
end_define

begin_define
define|#
directive|define
name|SEMOPS_INLINE
value|extern inline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SEMOPS_INLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TODO: Lazy encoding/decoding of fp values.  */
end_comment

begin_comment
comment|/* These don't really have a mode.  */
end_comment

begin_define
define|#
directive|define
name|ANDIF
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)&& (y))
end_define

begin_define
define|#
directive|define
name|ORIF
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) || (y))
end_define

begin_define
define|#
directive|define
name|SUBBI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) - (y))
end_define

begin_define
define|#
directive|define
name|ANDBI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)& (y))
end_define

begin_define
define|#
directive|define
name|ORBI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) | (y))
end_define

begin_define
define|#
directive|define
name|XORBI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) ^ (y))
end_define

begin_define
define|#
directive|define
name|NEGBI
parameter_list|(
name|x
parameter_list|)
value|(- (x))
end_define

begin_define
define|#
directive|define
name|NOTBI
parameter_list|(
name|x
parameter_list|)
value|(! (BI) (x))
end_define

begin_define
define|#
directive|define
name|INVBI
parameter_list|(
name|x
parameter_list|)
value|(~ (x))
end_define

begin_define
define|#
directive|define
name|EQBI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((BI) (x) == (BI) (y))
end_define

begin_define
define|#
directive|define
name|NEBI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((BI) (x) != (BI) (y))
end_define

begin_define
define|#
directive|define
name|LTBI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((BI) (x)< (BI) (y))
end_define

begin_define
define|#
directive|define
name|LEBI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((BI) (x)<= (BI) (y))
end_define

begin_define
define|#
directive|define
name|GTBI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((BI) (x)> (BI) (y))
end_define

begin_define
define|#
directive|define
name|GEBI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((BI) (x)>= (BI) (y))
end_define

begin_define
define|#
directive|define
name|LTUBI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((BI) (x)< (BI) (y))
end_define

begin_define
define|#
directive|define
name|LEUBI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((BI) (x)<= (BI) (y))
end_define

begin_define
define|#
directive|define
name|GTUBI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((BI) (x)> (BI) (y))
end_define

begin_define
define|#
directive|define
name|GEUBI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((BI) (x)>= (BI) (y))
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|ADDQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) + (y))
end_define

begin_define
define|#
directive|define
name|SUBQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) - (y))
end_define

begin_define
define|#
directive|define
name|MULQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) * (y))
end_define

begin_define
define|#
directive|define
name|DIVQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((QI) (x) / (QI) (y))
end_define

begin_define
define|#
directive|define
name|UDIVQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UQI) (x) / (UQI) (y))
end_define

begin_define
define|#
directive|define
name|MODQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((QI) (x) % (QI) (y))
end_define

begin_define
define|#
directive|define
name|UMODQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UQI) (x) % (UQI) (y))
end_define

begin_define
define|#
directive|define
name|SRAQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((QI) (x)>> (y))
end_define

begin_define
define|#
directive|define
name|SRLQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UQI) (x)>> (y))
end_define

begin_define
define|#
directive|define
name|SLLQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UQI) (x)<< (y))
end_define

begin_function_decl
specifier|extern
name|QI
name|RORQI
parameter_list|(
name|QI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|QI
name|ROLQI
parameter_list|(
name|QI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ANDQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)& (y))
end_define

begin_define
define|#
directive|define
name|ORQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) | (y))
end_define

begin_define
define|#
directive|define
name|XORQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) ^ (y))
end_define

begin_define
define|#
directive|define
name|NEGQI
parameter_list|(
name|x
parameter_list|)
value|(- (x))
end_define

begin_define
define|#
directive|define
name|NOTQI
parameter_list|(
name|x
parameter_list|)
value|(! (QI) (x))
end_define

begin_define
define|#
directive|define
name|INVQI
parameter_list|(
name|x
parameter_list|)
value|(~ (x))
end_define

begin_define
define|#
directive|define
name|ABSQI
parameter_list|(
name|x
parameter_list|)
value|((x)< 0 ? -(x) : (x))
end_define

begin_define
define|#
directive|define
name|EQQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((QI) (x) == (QI) (y))
end_define

begin_define
define|#
directive|define
name|NEQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((QI) (x) != (QI) (y))
end_define

begin_define
define|#
directive|define
name|LTQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((QI) (x)< (QI) (y))
end_define

begin_define
define|#
directive|define
name|LEQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((QI) (x)<= (QI) (y))
end_define

begin_define
define|#
directive|define
name|GTQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((QI) (x)> (QI) (y))
end_define

begin_define
define|#
directive|define
name|GEQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((QI) (x)>= (QI) (y))
end_define

begin_define
define|#
directive|define
name|LTUQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UQI) (x)< (UQI) (y))
end_define

begin_define
define|#
directive|define
name|LEUQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UQI) (x)<= (UQI) (y))
end_define

begin_define
define|#
directive|define
name|GTUQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UQI) (x)> (UQI) (y))
end_define

begin_define
define|#
directive|define
name|GEUQI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UQI) (x)>= (UQI) (y))
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|ADDHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) + (y))
end_define

begin_define
define|#
directive|define
name|SUBHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) - (y))
end_define

begin_define
define|#
directive|define
name|MULHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) * (y))
end_define

begin_define
define|#
directive|define
name|DIVHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((HI) (x) / (HI) (y))
end_define

begin_define
define|#
directive|define
name|UDIVHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UHI) (x) / (UHI) (y))
end_define

begin_define
define|#
directive|define
name|MODHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((HI) (x) % (HI) (y))
end_define

begin_define
define|#
directive|define
name|UMODHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UHI) (x) % (UHI) (y))
end_define

begin_define
define|#
directive|define
name|SRAHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((HI) (x)>> (y))
end_define

begin_define
define|#
directive|define
name|SRLHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UHI) (x)>> (y))
end_define

begin_define
define|#
directive|define
name|SLLHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UHI) (x)<< (y))
end_define

begin_function_decl
specifier|extern
name|HI
name|RORHI
parameter_list|(
name|HI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HI
name|ROLHI
parameter_list|(
name|HI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ANDHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)& (y))
end_define

begin_define
define|#
directive|define
name|ORHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) | (y))
end_define

begin_define
define|#
directive|define
name|XORHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) ^ (y))
end_define

begin_define
define|#
directive|define
name|NEGHI
parameter_list|(
name|x
parameter_list|)
value|(- (x))
end_define

begin_define
define|#
directive|define
name|NOTHI
parameter_list|(
name|x
parameter_list|)
value|(! (HI) (x))
end_define

begin_define
define|#
directive|define
name|INVHI
parameter_list|(
name|x
parameter_list|)
value|(~ (x))
end_define

begin_define
define|#
directive|define
name|ABSHI
parameter_list|(
name|x
parameter_list|)
value|((x)< 0 ? -(x) : (x))
end_define

begin_define
define|#
directive|define
name|EQHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((HI) (x) == (HI) (y))
end_define

begin_define
define|#
directive|define
name|NEHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((HI) (x) != (HI) (y))
end_define

begin_define
define|#
directive|define
name|LTHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((HI) (x)< (HI) (y))
end_define

begin_define
define|#
directive|define
name|LEHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((HI) (x)<= (HI) (y))
end_define

begin_define
define|#
directive|define
name|GTHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((HI) (x)> (HI) (y))
end_define

begin_define
define|#
directive|define
name|GEHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((HI) (x)>= (HI) (y))
end_define

begin_define
define|#
directive|define
name|LTUHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UHI) (x)< (UHI) (y))
end_define

begin_define
define|#
directive|define
name|LEUHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UHI) (x)<= (UHI) (y))
end_define

begin_define
define|#
directive|define
name|GTUHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UHI) (x)> (UHI) (y))
end_define

begin_define
define|#
directive|define
name|GEUHI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UHI) (x)>= (UHI) (y))
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|ADDSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) + (y))
end_define

begin_define
define|#
directive|define
name|SUBSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) - (y))
end_define

begin_define
define|#
directive|define
name|MULSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) * (y))
end_define

begin_define
define|#
directive|define
name|DIVSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((SI) (x) / (SI) (y))
end_define

begin_define
define|#
directive|define
name|UDIVSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((USI) (x) / (USI) (y))
end_define

begin_define
define|#
directive|define
name|MODSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((SI) (x) % (SI) (y))
end_define

begin_define
define|#
directive|define
name|UMODSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((USI) (x) % (USI) (y))
end_define

begin_define
define|#
directive|define
name|SRASI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((SI) (x)>> (y))
end_define

begin_define
define|#
directive|define
name|SRLSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((USI) (x)>> (y))
end_define

begin_define
define|#
directive|define
name|SLLSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((USI) (x)<< (y))
end_define

begin_function_decl
specifier|extern
name|SI
name|RORSI
parameter_list|(
name|SI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|SI
name|ROLSI
parameter_list|(
name|SI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ANDSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)& (y))
end_define

begin_define
define|#
directive|define
name|ORSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) | (y))
end_define

begin_define
define|#
directive|define
name|XORSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) ^ (y))
end_define

begin_define
define|#
directive|define
name|NEGSI
parameter_list|(
name|x
parameter_list|)
value|(- (x))
end_define

begin_define
define|#
directive|define
name|NOTSI
parameter_list|(
name|x
parameter_list|)
value|(! (SI) (x))
end_define

begin_define
define|#
directive|define
name|INVSI
parameter_list|(
name|x
parameter_list|)
value|(~ (x))
end_define

begin_define
define|#
directive|define
name|ABSSI
parameter_list|(
name|x
parameter_list|)
value|((x)< 0 ? -(x) : (x))
end_define

begin_define
define|#
directive|define
name|EQSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((SI) (x) == (SI) (y))
end_define

begin_define
define|#
directive|define
name|NESI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((SI) (x) != (SI) (y))
end_define

begin_define
define|#
directive|define
name|LTSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((SI) (x)< (SI) (y))
end_define

begin_define
define|#
directive|define
name|LESI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((SI) (x)<= (SI) (y))
end_define

begin_define
define|#
directive|define
name|GTSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((SI) (x)> (SI) (y))
end_define

begin_define
define|#
directive|define
name|GESI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((SI) (x)>= (SI) (y))
end_define

begin_define
define|#
directive|define
name|LTUSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((USI) (x)< (USI) (y))
end_define

begin_define
define|#
directive|define
name|LEUSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((USI) (x)<= (USI) (y))
end_define

begin_define
define|#
directive|define
name|GTUSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((USI) (x)> (USI) (y))
end_define

begin_define
define|#
directive|define
name|GEUSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((USI) (x)>= (USI) (y))
end_define

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|DI_FN_SUPPORT
end_ifdef

begin_function_decl
specifier|extern
name|DI
name|ADDDI
parameter_list|(
name|DI
parameter_list|,
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DI
name|SUBDI
parameter_list|(
name|DI
parameter_list|,
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DI
name|MULDI
parameter_list|(
name|DI
parameter_list|,
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DI
name|DIVDI
parameter_list|(
name|DI
parameter_list|,
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DI
name|UDIVDI
parameter_list|(
name|DI
parameter_list|,
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DI
name|MODDI
parameter_list|(
name|DI
parameter_list|,
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DI
name|UMODDI
parameter_list|(
name|DI
parameter_list|,
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DI
name|SRADI
parameter_list|(
name|DI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|UDI
name|SRLDI
parameter_list|(
name|UDI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|UDI
name|SLLDI
parameter_list|(
name|UDI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DI
name|RORDI
parameter_list|(
name|DI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DI
name|ROLDI
parameter_list|(
name|DI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DI
name|ANDDI
parameter_list|(
name|DI
parameter_list|,
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DI
name|ORDI
parameter_list|(
name|DI
parameter_list|,
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DI
name|XORDI
parameter_list|(
name|DI
parameter_list|,
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DI
name|NEGDI
parameter_list|(
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|NOTDI
parameter_list|(
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DI
name|INVDI
parameter_list|(
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|EQDI
parameter_list|(
name|DI
parameter_list|,
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|NEDI
parameter_list|(
name|DI
parameter_list|,
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|LTDI
parameter_list|(
name|DI
parameter_list|,
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|LEDI
parameter_list|(
name|DI
parameter_list|,
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|GTDI
parameter_list|(
name|DI
parameter_list|,
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|GEDI
parameter_list|(
name|DI
parameter_list|,
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|LTUDI
parameter_list|(
name|UDI
parameter_list|,
name|UDI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|LEUDI
parameter_list|(
name|UDI
parameter_list|,
name|UDI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|GTUDI
parameter_list|(
name|UDI
parameter_list|,
name|UDI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|GEUDI
parameter_list|(
name|UDI
parameter_list|,
name|UDI
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! DI_FN_SUPPORT */
end_comment

begin_define
define|#
directive|define
name|ADDDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) + (y))
end_define

begin_define
define|#
directive|define
name|SUBDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) - (y))
end_define

begin_define
define|#
directive|define
name|MULDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) * (y))
end_define

begin_define
define|#
directive|define
name|DIVDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((DI) (x) / (DI) (y))
end_define

begin_define
define|#
directive|define
name|UDIVDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UDI) (x) / (UDI) (y))
end_define

begin_define
define|#
directive|define
name|MODDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((DI) (x) % (DI) (y))
end_define

begin_define
define|#
directive|define
name|UMODDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UDI) (x) % (UDI) (y))
end_define

begin_define
define|#
directive|define
name|SRADI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((DI) (x)>> (y))
end_define

begin_define
define|#
directive|define
name|SRLDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UDI) (x)>> (y))
end_define

begin_define
define|#
directive|define
name|SLLDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UDI) (x)<< (y))
end_define

begin_function_decl
specifier|extern
name|DI
name|RORDI
parameter_list|(
name|DI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DI
name|ROLDI
parameter_list|(
name|DI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ANDDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)& (y))
end_define

begin_define
define|#
directive|define
name|ORDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) | (y))
end_define

begin_define
define|#
directive|define
name|XORDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) ^ (y))
end_define

begin_define
define|#
directive|define
name|NEGDI
parameter_list|(
name|x
parameter_list|)
value|(- (x))
end_define

begin_define
define|#
directive|define
name|NOTDI
parameter_list|(
name|x
parameter_list|)
value|(! (DI) (x))
end_define

begin_define
define|#
directive|define
name|INVDI
parameter_list|(
name|x
parameter_list|)
value|(~ (x))
end_define

begin_define
define|#
directive|define
name|ABSDI
parameter_list|(
name|x
parameter_list|)
value|((x)< 0 ? -(x) : (x))
end_define

begin_define
define|#
directive|define
name|EQDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((DI) (x) == (DI) (y))
end_define

begin_define
define|#
directive|define
name|NEDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((DI) (x) != (DI) (y))
end_define

begin_define
define|#
directive|define
name|LTDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((DI) (x)< (DI) (y))
end_define

begin_define
define|#
directive|define
name|LEDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((DI) (x)<= (DI) (y))
end_define

begin_define
define|#
directive|define
name|GTDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((DI) (x)> (DI) (y))
end_define

begin_define
define|#
directive|define
name|GEDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((DI) (x)>= (DI) (y))
end_define

begin_define
define|#
directive|define
name|LTUDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UDI) (x)< (UDI) (y))
end_define

begin_define
define|#
directive|define
name|LEUDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UDI) (x)<= (UDI) (y))
end_define

begin_define
define|#
directive|define
name|GTUDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UDI) (x)> (UDI) (y))
end_define

begin_define
define|#
directive|define
name|GEUDI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((UDI) (x)>= (UDI) (y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DI_FN_SUPPORT */
end_comment

begin_escape
end_escape

begin_define
define|#
directive|define
name|EXTBIQI
parameter_list|(
name|x
parameter_list|)
value|((QI) (BI) (x))
end_define

begin_define
define|#
directive|define
name|EXTBIHI
parameter_list|(
name|x
parameter_list|)
value|((HI) (BI) (x))
end_define

begin_define
define|#
directive|define
name|EXTBISI
parameter_list|(
name|x
parameter_list|)
value|((SI) (BI) (x))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DI_FN_SUPPORT
argument_list|)
end_if

begin_function_decl
specifier|extern
name|DI
name|EXTBIDI
parameter_list|(
name|BI
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTBIDI
parameter_list|(
name|x
parameter_list|)
value|((DI) (BI) (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EXTQIHI
parameter_list|(
name|x
parameter_list|)
value|((HI) (QI) (x))
end_define

begin_define
define|#
directive|define
name|EXTQISI
parameter_list|(
name|x
parameter_list|)
value|((SI) (QI) (x))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DI_FN_SUPPORT
argument_list|)
end_if

begin_function_decl
specifier|extern
name|DI
name|EXTQIDI
parameter_list|(
name|QI
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTQIDI
parameter_list|(
name|x
parameter_list|)
value|((DI) (QI) (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EXTHIHI
parameter_list|(
name|x
parameter_list|)
value|((HI) (HI) (x))
end_define

begin_define
define|#
directive|define
name|EXTHISI
parameter_list|(
name|x
parameter_list|)
value|((SI) (HI) (x))
end_define

begin_define
define|#
directive|define
name|EXTSISI
parameter_list|(
name|x
parameter_list|)
value|((SI) (SI) (x))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DI_FN_SUPPORT
argument_list|)
end_if

begin_function_decl
specifier|extern
name|DI
name|EXTHIDI
parameter_list|(
name|HI
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTHIDI
parameter_list|(
name|x
parameter_list|)
value|((DI) (HI) (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DI_FN_SUPPORT
argument_list|)
end_if

begin_function_decl
specifier|extern
name|DI
name|EXTSIDI
parameter_list|(
name|SI
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTSIDI
parameter_list|(
name|x
parameter_list|)
value|((DI) (SI) (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_define
define|#
directive|define
name|ZEXTBIQI
parameter_list|(
name|x
parameter_list|)
value|((QI) (BI) (x))
end_define

begin_define
define|#
directive|define
name|ZEXTBIHI
parameter_list|(
name|x
parameter_list|)
value|((HI) (BI) (x))
end_define

begin_define
define|#
directive|define
name|ZEXTBISI
parameter_list|(
name|x
parameter_list|)
value|((SI) (BI) (x))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DI_FN_SUPPORT
argument_list|)
end_if

begin_function_decl
specifier|extern
name|DI
name|ZEXTBIDI
parameter_list|(
name|BI
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ZEXTBIDI
parameter_list|(
name|x
parameter_list|)
value|((DI) (BI) (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ZEXTQIHI
parameter_list|(
name|x
parameter_list|)
value|((HI) (UQI) (x))
end_define

begin_define
define|#
directive|define
name|ZEXTQISI
parameter_list|(
name|x
parameter_list|)
value|((SI) (UQI) (x))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DI_FN_SUPPORT
argument_list|)
end_if

begin_function_decl
specifier|extern
name|DI
name|ZEXTQIDI
parameter_list|(
name|QI
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ZEXTQIDI
parameter_list|(
name|x
parameter_list|)
value|((DI) (UQI) (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ZEXTHISI
parameter_list|(
name|x
parameter_list|)
value|((SI) (UHI) (x))
end_define

begin_define
define|#
directive|define
name|ZEXTHIHI
parameter_list|(
name|x
parameter_list|)
value|((HI) (UHI) (x))
end_define

begin_define
define|#
directive|define
name|ZEXTSISI
parameter_list|(
name|x
parameter_list|)
value|((SI) (USI) (x))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DI_FN_SUPPORT
argument_list|)
end_if

begin_function_decl
specifier|extern
name|DI
name|ZEXTHIDI
parameter_list|(
name|HI
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ZEXTHIDI
parameter_list|(
name|x
parameter_list|)
value|((DI) (UHI) (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DI_FN_SUPPORT
argument_list|)
end_if

begin_function_decl
specifier|extern
name|DI
name|ZEXTSIDI
parameter_list|(
name|SI
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ZEXTSIDI
parameter_list|(
name|x
parameter_list|)
value|((DI) (USI) (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_define
define|#
directive|define
name|TRUNCQIBI
parameter_list|(
name|x
parameter_list|)
value|((BI) (QI) (x))
end_define

begin_define
define|#
directive|define
name|TRUNCHIBI
parameter_list|(
name|x
parameter_list|)
value|((BI) (HI) (x))
end_define

begin_define
define|#
directive|define
name|TRUNCHIQI
parameter_list|(
name|x
parameter_list|)
value|((QI) (HI) (x))
end_define

begin_define
define|#
directive|define
name|TRUNCSIBI
parameter_list|(
name|x
parameter_list|)
value|((BI) (SI) (x))
end_define

begin_define
define|#
directive|define
name|TRUNCSIQI
parameter_list|(
name|x
parameter_list|)
value|((QI) (SI) (x))
end_define

begin_define
define|#
directive|define
name|TRUNCSIHI
parameter_list|(
name|x
parameter_list|)
value|((HI) (SI) (x))
end_define

begin_define
define|#
directive|define
name|TRUNCSISI
parameter_list|(
name|x
parameter_list|)
value|((SI) (SI) (x))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DI_FN_SUPPORT
argument_list|)
end_if

begin_function_decl
specifier|extern
name|BI
name|TRUNCDIBI
parameter_list|(
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TRUNCDIBI
parameter_list|(
name|x
parameter_list|)
value|((BI) (DI) (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DI_FN_SUPPORT
argument_list|)
end_if

begin_function_decl
specifier|extern
name|QI
name|TRUNCDIQI
parameter_list|(
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TRUNCDIQI
parameter_list|(
name|x
parameter_list|)
value|((QI) (DI) (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DI_FN_SUPPORT
argument_list|)
end_if

begin_function_decl
specifier|extern
name|HI
name|TRUNCDIHI
parameter_list|(
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TRUNCDIHI
parameter_list|(
name|x
parameter_list|)
value|((HI) (DI) (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DI_FN_SUPPORT
argument_list|)
end_if

begin_function_decl
specifier|extern
name|SI
name|TRUNCDISI
parameter_list|(
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TRUNCDISI
parameter_list|(
name|x
parameter_list|)
value|((SI) (DI) (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Composing/decomposing the various types.    Word ordering is endian-independent.  Words are specified most to least    significant and word number 0 is the most significant word.    ??? May also wish an endian-dependent version.  Later.  */
end_comment

begin_function_decl
name|QI
name|SUBWORDSIQI
parameter_list|(
name|SI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HI
name|SUBWORDSIHI
parameter_list|(
name|SI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SI
name|SUBWORDSFSI
parameter_list|(
name|SF
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SF
name|SUBWORDSISF
parameter_list|(
name|SI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DI
name|SUBWORDDFDI
parameter_list|(
name|DF
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DF
name|SUBWORDDIDF
parameter_list|(
name|DI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QI
name|SUBWORDDIQI
parameter_list|(
name|DI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HI
name|SUBWORDDIHI
parameter_list|(
name|DI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SI
name|SUBWORDDISI
parameter_list|(
name|DI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SI
name|SUBWORDDFSI
parameter_list|(
name|DF
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SI
name|SUBWORDXFSI
parameter_list|(
name|XF
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SI
name|SUBWORDTFSI
parameter_list|(
name|TF
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UQI
name|SUBWORDSIUQI
parameter_list|(
name|SI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UQI
name|SUBWORDDIUQI
parameter_list|(
name|DI
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SEMOPS_DEFINE_INLINE
end_ifdef

begin_function
name|SEMOPS_INLINE
name|SF
name|SUBWORDSISF
parameter_list|(
name|SI
name|in
parameter_list|)
block|{
union|union
block|{
name|SI
name|in
decl_stmt|;
name|SF
name|out
decl_stmt|;
block|}
name|x
union|;
name|x
operator|.
name|in
operator|=
name|in
expr_stmt|;
return|return
name|x
operator|.
name|out
return|;
block|}
end_function

begin_function
name|SEMOPS_INLINE
name|DF
name|SUBWORDDIDF
parameter_list|(
name|DI
name|in
parameter_list|)
block|{
union|union
block|{
name|DI
name|in
decl_stmt|;
name|DF
name|out
decl_stmt|;
block|}
name|x
union|;
name|x
operator|.
name|in
operator|=
name|in
expr_stmt|;
return|return
name|x
operator|.
name|out
return|;
block|}
end_function

begin_function
name|SEMOPS_INLINE
name|QI
name|SUBWORDSIQI
parameter_list|(
name|SI
name|in
parameter_list|,
name|int
name|byte
parameter_list|)
block|{
name|assert
argument_list|(
name|byte
operator|>=
literal|0
operator|&&
name|byte
operator|<=
literal|3
argument_list|)
expr_stmt|;
return|return
call|(
name|UQI
call|)
argument_list|(
name|in
operator|>>
operator|(
literal|8
operator|*
operator|(
literal|3
operator|-
name|byte
operator|)
operator|)
argument_list|)
operator|&
literal|0xFF
return|;
block|}
end_function

begin_function
name|SEMOPS_INLINE
name|UQI
name|SUBWORDSIUQI
parameter_list|(
name|SI
name|in
parameter_list|,
name|int
name|byte
parameter_list|)
block|{
name|assert
argument_list|(
name|byte
operator|>=
literal|0
operator|&&
name|byte
operator|<=
literal|3
argument_list|)
expr_stmt|;
return|return
call|(
name|UQI
call|)
argument_list|(
name|in
operator|>>
operator|(
literal|8
operator|*
operator|(
literal|3
operator|-
name|byte
operator|)
operator|)
argument_list|)
operator|&
literal|0xFF
return|;
block|}
end_function

begin_function
name|SEMOPS_INLINE
name|QI
name|SUBWORDDIQI
parameter_list|(
name|DI
name|in
parameter_list|,
name|int
name|byte
parameter_list|)
block|{
name|assert
argument_list|(
name|byte
operator|>=
literal|0
operator|&&
name|byte
operator|<=
literal|7
argument_list|)
expr_stmt|;
return|return
call|(
name|UQI
call|)
argument_list|(
name|in
operator|>>
operator|(
literal|8
operator|*
operator|(
literal|7
operator|-
name|byte
operator|)
operator|)
argument_list|)
operator|&
literal|0xFF
return|;
block|}
end_function

begin_function
name|SEMOPS_INLINE
name|HI
name|SUBWORDDIHI
parameter_list|(
name|DI
name|in
parameter_list|,
name|int
name|word
parameter_list|)
block|{
name|assert
argument_list|(
name|word
operator|>=
literal|0
operator|&&
name|word
operator|<=
literal|3
argument_list|)
expr_stmt|;
return|return
call|(
name|UHI
call|)
argument_list|(
name|in
operator|>>
operator|(
literal|16
operator|*
operator|(
literal|3
operator|-
name|word
operator|)
operator|)
argument_list|)
operator|&
literal|0xFFFF
return|;
block|}
end_function

begin_function
name|SEMOPS_INLINE
name|HI
name|SUBWORDSIHI
parameter_list|(
name|SI
name|in
parameter_list|,
name|int
name|word
parameter_list|)
block|{
if|if
condition|(
name|word
operator|==
literal|0
condition|)
return|return
operator|(
name|USI
operator|)
name|in
operator|>>
literal|16
return|;
else|else
return|return
name|in
return|;
block|}
end_function

begin_function
name|SEMOPS_INLINE
name|SI
name|SUBWORDSFSI
parameter_list|(
name|SF
name|in
parameter_list|)
block|{
union|union
block|{
name|SF
name|in
decl_stmt|;
name|SI
name|out
decl_stmt|;
block|}
name|x
union|;
name|x
operator|.
name|in
operator|=
name|in
expr_stmt|;
return|return
name|x
operator|.
name|out
return|;
block|}
end_function

begin_function
name|SEMOPS_INLINE
name|DI
name|SUBWORDDFDI
parameter_list|(
name|DF
name|in
parameter_list|)
block|{
union|union
block|{
name|DF
name|in
decl_stmt|;
name|DI
name|out
decl_stmt|;
block|}
name|x
union|;
name|x
operator|.
name|in
operator|=
name|in
expr_stmt|;
return|return
name|x
operator|.
name|out
return|;
block|}
end_function

begin_function
name|SEMOPS_INLINE
name|UQI
name|SUBWORDDIUQI
parameter_list|(
name|DI
name|in
parameter_list|,
name|int
name|byte
parameter_list|)
block|{
name|assert
argument_list|(
name|byte
operator|>=
literal|0
operator|&&
name|byte
operator|<=
literal|7
argument_list|)
expr_stmt|;
return|return
call|(
name|UQI
call|)
argument_list|(
name|in
operator|>>
operator|(
literal|8
operator|*
operator|(
literal|7
operator|-
name|byte
operator|)
operator|)
argument_list|)
return|;
block|}
end_function

begin_function
name|SEMOPS_INLINE
name|SI
name|SUBWORDDISI
parameter_list|(
name|DI
name|in
parameter_list|,
name|int
name|word
parameter_list|)
block|{
if|if
condition|(
name|word
operator|==
literal|0
condition|)
return|return
operator|(
name|UDI
operator|)
name|in
operator|>>
literal|32
return|;
else|else
return|return
name|in
return|;
block|}
end_function

begin_function
name|SEMOPS_INLINE
name|SI
name|SUBWORDDFSI
parameter_list|(
name|DF
name|in
parameter_list|,
name|int
name|word
parameter_list|)
block|{
comment|/* Note: typedef UDI DF; */
if|if
condition|(
name|word
operator|==
literal|0
condition|)
return|return
operator|(
name|UDI
operator|)
name|in
operator|>>
literal|32
return|;
else|else
return|return
name|in
return|;
block|}
end_function

begin_function
name|SEMOPS_INLINE
name|SI
name|SUBWORDXFSI
parameter_list|(
name|XF
name|in
parameter_list|,
name|int
name|word
parameter_list|)
block|{
comment|/* Note: typedef struct { SI parts[3]; } XF; */
union|union
block|{
name|XF
name|in
decl_stmt|;
name|SI
name|out
index|[
literal|3
index|]
decl_stmt|;
block|}
name|x
union|;
name|x
operator|.
name|in
operator|=
name|in
expr_stmt|;
return|return
name|x
operator|.
name|out
index|[
name|word
index|]
return|;
block|}
end_function

begin_function
name|SEMOPS_INLINE
name|SI
name|SUBWORDTFSI
parameter_list|(
name|TF
name|in
parameter_list|,
name|int
name|word
parameter_list|)
block|{
comment|/* Note: typedef struct { SI parts[4]; } TF; */
union|union
block|{
name|TF
name|in
decl_stmt|;
name|SI
name|out
index|[
literal|4
index|]
decl_stmt|;
block|}
name|x
union|;
name|x
operator|.
name|in
operator|=
name|in
expr_stmt|;
return|return
name|x
operator|.
name|out
index|[
name|word
index|]
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUBWORD,JOIN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CGEN_SEM_OPS_H */
end_comment

end_unit

