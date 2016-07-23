begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===------------  support/xlocale/__nop_locale_mgmt.h -----------------===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
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
name|_LIBCPP_SUPPORT_XLOCALE_NOP_LOCALE_MGMT_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_SUPPORT_XLOCALE_NOP_LOCALE_MGMT_H
end_define

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
comment|// Patch over lack of extended locale support
typedef|typedef
name|void
modifier|*
name|locale_t
typedef|;
specifier|static
specifier|inline
name|locale_t
name|duplocale
parameter_list|(
name|locale_t
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
specifier|static
specifier|inline
name|void
name|freelocale
parameter_list|(
name|locale_t
parameter_list|)
block|{ }
specifier|static
specifier|inline
name|locale_t
name|newlocale
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|locale_t
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
specifier|static
specifier|inline
name|locale_t
name|uselocale
parameter_list|(
name|locale_t
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
define|#
directive|define
name|LC_COLLATE_MASK
value|(1<< LC_COLLATE)
define|#
directive|define
name|LC_CTYPE_MASK
value|(1<< LC_CTYPE)
define|#
directive|define
name|LC_MESSAGES_MASK
value|(1<< LC_MESSAGES)
define|#
directive|define
name|LC_MONETARY_MASK
value|(1<< LC_MONETARY)
define|#
directive|define
name|LC_NUMERIC_MASK
value|(1<< LC_NUMERIC)
define|#
directive|define
name|LC_TIME_MASK
value|(1<< LC_TIME)
define|#
directive|define
name|LC_ALL_MASK
value|(LC_COLLATE_MASK|\                      LC_CTYPE_MASK|\                      LC_MONETARY_MASK|\                      LC_NUMERIC_MASK|\                      LC_TIME_MASK|\                      LC_MESSAGES_MASK)
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_SUPPORT_XLOCALE_NOP_LOCALE_MGMT_H
end_comment

end_unit

