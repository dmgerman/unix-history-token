begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file       This module contains generic macros for an assembly writer.  Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED. **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ASM_H_
end_ifndef

begin_define
define|#
directive|define
name|_ASM_H_
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|PROCEDURE_ENTRY
parameter_list|(
name|name
parameter_list|)
value|.##text;            \   .##type name, @function; \   .##proc name; \   name::
end_define

begin_define
define|#
directive|define
name|PROCEDURE_EXIT
parameter_list|(
name|name
parameter_list|)
value|.##endp name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _ASM_H
end_comment

end_unit

