begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sound/awe_version.h  *  * Version defines for the AWE32/Sound Blaster 32 wave table synth driver.  *   version 0.4.2c; Oct. 7, 1997  *  * Copyright (C) 1996,1997 Takashi Iwai  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* AWE32 driver version number */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AWE_VERSION_H_DEF
end_ifndef

begin_define
define|#
directive|define
name|AWE_VERSION_H_DEF
end_define

begin_define
define|#
directive|define
name|AWE_VERSION_NUMBER
value|0x00040203
end_define

begin_define
define|#
directive|define
name|AWEDRV_VERSION
value|"0.4.2c"
end_define

begin_define
define|#
directive|define
name|AWE_MAJOR_VERSION
parameter_list|(
name|id
parameter_list|)
value|(((id)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|AWE_MINOR_VERSION
parameter_list|(
name|id
parameter_list|)
value|(((id)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|AWE_TINY_VERSION
parameter_list|(
name|id
parameter_list|)
value|((id)& 0xff)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

