begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* emul-target.h.  Default values for struct emulation defined in emul.h    Copyright 2001 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|emul_init
end_ifndef

begin_define
define|#
directive|define
name|emul_init
value|common_emul_init
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|emul_bfd_name
end_ifndef

begin_define
define|#
directive|define
name|emul_bfd_name
value|default_emul_bfd_name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|emul_local_labels_fb
end_ifndef

begin_define
define|#
directive|define
name|emul_local_labels_fb
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|emul_local_labels_dollar
end_ifndef

begin_define
define|#
directive|define
name|emul_local_labels_dollar
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|emul_leading_underscore
end_ifndef

begin_define
define|#
directive|define
name|emul_leading_underscore
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|emul_strip_underscore
end_ifndef

begin_define
define|#
directive|define
name|emul_strip_underscore
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|emul_default_endian
end_ifndef

begin_define
define|#
directive|define
name|emul_default_endian
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|emul_fake_label_name
end_ifndef

begin_define
define|#
directive|define
name|emul_fake_label_name
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|emulation
name|emul_struct_name
init|=
block|{
literal|0
block|,
name|emul_name
block|,
name|emul_init
block|,
name|emul_bfd_name
block|,
name|emul_local_labels_fb
block|,
name|emul_local_labels_dollar
block|,
name|emul_leading_underscore
block|,
name|emul_strip_underscore
block|,
name|emul_default_endian
block|,
name|emul_fake_label_name
block|,
name|emul_format
block|, }
decl_stmt|;
end_decl_stmt

end_unit

