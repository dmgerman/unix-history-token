begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD support for the FRV processor.    Copyright 2002, 2003, 2004, 2007 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"libbfd.h"
end_include

begin_define
define|#
directive|define
name|FRV_ARCH
parameter_list|(
name|MACHINE
parameter_list|,
name|NAME
parameter_list|,
name|DEFAULT
parameter_list|,
name|NEXT
parameter_list|)
define|\
value|{									\   32,
comment|/* 32 bits in a word */
value|\   32,
comment|/* 32 bits in an address */
value|\   8,
comment|/* 8 bits in a byte */
value|\   bfd_arch_frv,
comment|/* architecture */
value|\   MACHINE,
comment|/* which machine */
value|\   "frv",
comment|/* architecture name */
value|\   NAME,
comment|/* machine name */
value|\   4,
comment|/* default alignment */
value|\   DEFAULT,
comment|/* is this the default? */
value|\   bfd_default_compatible,
comment|/* architecture comparison fn */
value|\   bfd_default_scan,
comment|/* string to architecture convert fn */
value|\   NEXT
comment|/* next in list */
value|\ }
end_define

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
name|arch_info_300
init|=
name|FRV_ARCH
argument_list|(
name|bfd_mach_fr300
argument_list|,
literal|"fr300"
argument_list|,
name|FALSE
argument_list|,
operator|(
name|bfd_arch_info_type
operator|*
operator|)
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
name|arch_info_400
init|=
name|FRV_ARCH
argument_list|(
name|bfd_mach_fr400
argument_list|,
literal|"fr400"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_300
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
name|arch_info_450
init|=
name|FRV_ARCH
argument_list|(
name|bfd_mach_fr450
argument_list|,
literal|"fr450"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_400
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
name|arch_info_500
init|=
name|FRV_ARCH
argument_list|(
name|bfd_mach_fr500
argument_list|,
literal|"fr500"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_450
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
name|arch_info_550
init|=
name|FRV_ARCH
argument_list|(
name|bfd_mach_fr550
argument_list|,
literal|"fr550"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_500
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
name|arch_info_simple
init|=
name|FRV_ARCH
argument_list|(
name|bfd_mach_frvsimple
argument_list|,
literal|"simple"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_550
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
name|arch_info_tomcat
init|=
name|FRV_ARCH
argument_list|(
name|bfd_mach_frvtomcat
argument_list|,
literal|"tomcat"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_simple
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_frv_arch
init|=
name|FRV_ARCH
argument_list|(
name|bfd_mach_frv
argument_list|,
literal|"frv"
argument_list|,
name|TRUE
argument_list|,
operator|&
name|arch_info_tomcat
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

