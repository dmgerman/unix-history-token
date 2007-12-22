begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Macro definitions to used to support 32/64-bit code in Darwin's  *  assembly files.  *  *   Copyright (C) 2004 Free Software Foundation, Inc.  *   * This file is free software; you can redistribute it and/or modify it  * under the terms of the GNU General Public License as published by the  * Free Software Foundation; either version 2, or (at your option) any  * later version.  *   * In addition to the permissions in the GNU General Public License, the  * Free Software Foundation gives you unlimited permission to link the  * compiled version of this file with other programs, and to distribute  * those programs without any restriction coming from the use of this  * file.  (The General Public License restrictions do apply in other  * respects; for example, they cover modification of the file, and  * distribution when not linked into another program.)  *   * This file is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *   * You should have received a copy of the GNU General Public License  * along with this program; see the file COPYING.  If not, write to  * the Free Software Foundation, 51 Franklin Street, Fifth Floor,  * Boston, MA 02110-1301, USA.  *   *  As a special exception, if you link this library with files  *  compiled with GCC to produce an executable, this does not cause the  *  resulting executable to be covered by the GNU General Public License.  *  This exception does not however invalidate any other reasons why the  *  executable file might be covered by the GNU General Public License.  */
end_comment

begin_comment
comment|/* These are donated from /usr/include/architecture/ppc . */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ppc64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|MODE_CHOICE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|y
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MODE_CHOICE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|cmpg
value|MODE_CHOICE(cmpw, cmpd)
end_define

begin_define
define|#
directive|define
name|lg
value|MODE_CHOICE(lwz, ld)
end_define

begin_define
define|#
directive|define
name|stg
value|MODE_CHOICE(stw, std)
end_define

begin_define
define|#
directive|define
name|lgx
value|MODE_CHOICE(lwzx, ldx)
end_define

begin_define
define|#
directive|define
name|stgx
value|MODE_CHOICE(stwx, stdx)
end_define

begin_define
define|#
directive|define
name|lgu
value|MODE_CHOICE(lwzu, ldu)
end_define

begin_define
define|#
directive|define
name|stgu
value|MODE_CHOICE(stwu, stdu)
end_define

begin_define
define|#
directive|define
name|lgux
value|MODE_CHOICE(lwzux, ldux)
end_define

begin_define
define|#
directive|define
name|stgux
value|MODE_CHOICE(stwux, stdux)
end_define

begin_define
define|#
directive|define
name|lgwa
value|MODE_CHOICE(lwz, lwa)
end_define

begin_define
define|#
directive|define
name|g_long
value|MODE_CHOICE(long, quad)
end_define

begin_comment
comment|/* usage is ".g_long" */
end_comment

begin_define
define|#
directive|define
name|GPR_BYTES
value|MODE_CHOICE(4,8)
end_define

begin_comment
comment|/* size of a GPR in bytes */
end_comment

begin_define
define|#
directive|define
name|LOG2_GPR_BYTES
value|MODE_CHOICE(2,3)
end_define

begin_comment
comment|/* log2(GPR_BYTES) */
end_comment

begin_define
define|#
directive|define
name|SAVED_LR_OFFSET
value|MODE_CHOICE(8,16)
end_define

begin_comment
comment|/* position of saved 						   LR in frame */
end_comment

end_unit

