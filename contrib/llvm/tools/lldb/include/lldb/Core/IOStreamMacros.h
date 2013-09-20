begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- IOStreamMacros.h ----------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_IOStreamMacros_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_IOStreamMacros_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|<iomanip>
end_include

begin_define
define|#
directive|define
name|RAW_HEXBASE
value|std::setfill('0')<< std::hex<< std::right
end_define

begin_define
define|#
directive|define
name|HEXBASE
value|'0'<< 'x'<< RAW_HEXBASE
end_define

begin_define
define|#
directive|define
name|RAWHEX8
parameter_list|(
name|x
parameter_list|)
value|RAW_HEXBASE<< std::setw(2)<< ((uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|RAWHEX16
value|RAW_HEXBASE<< std::setw(4)
end_define

begin_define
define|#
directive|define
name|RAWHEX32
value|RAW_HEXBASE<< std::setw(8)
end_define

begin_define
define|#
directive|define
name|RAWHEX64
value|RAW_HEXBASE<< std::setw(16)
end_define

begin_define
define|#
directive|define
name|HEX8
parameter_list|(
name|x
parameter_list|)
value|HEXBASE<< std::setw(2)<< ((uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|HEX16
value|HEXBASE<< std::setw(4)
end_define

begin_define
define|#
directive|define
name|HEX32
value|HEXBASE<< std::setw(8)
end_define

begin_define
define|#
directive|define
name|HEX64
value|HEXBASE<< std::setw(16)
end_define

begin_define
define|#
directive|define
name|RAW_HEX
parameter_list|(
name|x
parameter_list|)
value|RAW_HEXBASE<< std::setw(sizeof(x)*2)<< (x)
end_define

begin_define
define|#
directive|define
name|HEX
parameter_list|(
name|x
parameter_list|)
value|HEXBASE<< std::setw(sizeof(x)*2)<< (x)
end_define

begin_define
define|#
directive|define
name|HEX_SIZE
parameter_list|(
name|x
parameter_list|,
name|sz
parameter_list|)
value|HEXBASE<< std::setw((sz))<< (x)
end_define

begin_define
define|#
directive|define
name|STRING_WIDTH
parameter_list|(
name|w
parameter_list|)
value|std::setfill(' ')<< std::setw(w)
end_define

begin_define
define|#
directive|define
name|LEFT_STRING_WIDTH
parameter_list|(
name|s
parameter_list|,
name|w
parameter_list|)
value|std::left<< std::setfill(' ')<< std::setw(w)<< (s)<< std::right
end_define

begin_define
define|#
directive|define
name|DECIMAL
value|std::dec<< std::setfill(' ')
end_define

begin_define
define|#
directive|define
name|DECIMAL_WIDTH
parameter_list|(
name|w
parameter_list|)
value|DECIMAL<< std::setw(w)
end_define

begin_comment
comment|//#define FLOAT(n, d)       std::setfill(' ')<< std::setw((n)+(d)+1)<< std::setprecision(d)<< std::showpoint<< std::fixed
end_comment

begin_define
define|#
directive|define
name|INDENT_WITH_SPACES
parameter_list|(
name|iword_idx
parameter_list|)
value|std::setfill(' ')<< std::setw((iword_idx))<< ""
end_define

begin_define
define|#
directive|define
name|INDENT_WITH_TABS
parameter_list|(
name|iword_idx
parameter_list|)
value|std::setfill('\t')<< std::setw((iword_idx))<< ""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_IOStreamMacros_h_
end_comment

end_unit

