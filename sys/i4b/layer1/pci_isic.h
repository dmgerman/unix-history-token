begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   Copyright (c) 1999 Martin Husemann. All rights reserved.  *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *      documentation and/or other materials provided with the distribution.  *   3. Neither the name of the author nor the names of any co-contributors  *      may be used to endorse or promote products derived from this software  *      without specific prior written permission.  *   4. Altered versions must be plainly marked as such, and must not be  *      misrepresented as being the original software and/or documentation.  *     *   THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  *   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *   ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  *   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  *   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  *   OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  *   OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  *   SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	pci_isic.h - pci bus frontend for i4b_isic driver  *	-------------------------------------------------  *  * $FreeBSD$   *  *      last edit-date: [Wed Mar 10 07:22:08 1999]  *  *	-mh	original implementation  *  *---------------------------------------------------------------------------*/
end_comment

begin_struct
struct|struct
name|pci_isic_softc
block|{
name|struct
name|isic_softc
name|sc_isic
decl_stmt|;
comment|/* parent class */
comment|/* PCI-specific goo */
name|void
modifier|*
name|sc_ih
decl_stmt|;
comment|/* interrupt handler */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|void
name|isic_attach_Eqs1pp
name|__P
argument_list|(
operator|(
expr|struct
name|pci_isic_softc
operator|*
name|psc
operator|,
expr|struct
name|pci_attach_args
operator|*
name|pa
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|isic_attach_fritzPci
name|__P
argument_list|(
operator|(
expr|struct
name|pci_isic_softc
operator|*
name|psc
operator|,
expr|struct
name|pci_attach_args
operator|*
name|pa
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

