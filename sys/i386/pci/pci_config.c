begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************** ** **  $Id: pci_config.c,v 2.0.0.1 94/08/18 23:07:28 wolf Exp $ ** **  @PCI@ this should be part of "ioconf.c". ** **  The config-utility should build it! ** **------------------------------------------------------------------------- ** ** Copyright (c) 1994 Wolfgang Stanglmeier.  All rights reserved. ** ** Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions ** are met: ** 1. Redistributions of source code must retain the above copyright **    notice, this list of conditions and the following disclaimer. ** 2. Redistributions in binary form must reproduce the above copyright **    notice, this list of conditions and the following disclaimer in the **    documentation and/or other materials provided with the distribution. ** 3. The name of the author may not be used to endorse or promote products **    derived from this software without specific prior written permission. ** ** THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR ** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES ** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. ** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, ** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT ** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF ** THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ** **------------------------------------------------------------------------- ** **  $Log:	pci_config.c,v $ **  Revision 2.0.0.1  94/08/18  23:07:28  wolf **  Copyright message. **  Hook for DEC ethernet driver "de". **   **  Revision 2.0  94/07/10  15:53:30  wolf **  FreeBSD release. **   **  Revision 1.0  94/06/07  20:04:37  wolf **  Beta release. **   *************************************************************************** */
end_comment

begin_include
include|#
directive|include
file|"types.h"
end_include

begin_include
include|#
directive|include
file|"i386/pci/pci.h"
end_include

begin_include
include|#
directive|include
file|"i386/pci/pci_device.h"
end_include

begin_include
include|#
directive|include
file|"ncr.h"
end_include

begin_if
if|#
directive|if
name|NNCR
operator|>
literal|0
end_if

begin_decl_stmt
specifier|extern
name|struct
name|pci_driver
name|ncrdevice
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"de.h"
end_include

begin_if
if|#
directive|if
name|NDE
operator|>
literal|0
end_if

begin_decl_stmt
specifier|extern
name|struct
name|pci_driver
name|dedevice
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|pci_device
name|pci_devtab
index|[]
init|=
block|{
if|#
directive|if
name|NNCR
operator|>
literal|0
block|{
operator|&
name|ncrdevice
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|NDE
operator|>
literal|0
block|{
operator|&
name|dedevice
block|}
block|,
endif|#
directive|endif
block|{
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

