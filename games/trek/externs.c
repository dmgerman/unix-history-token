begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)externs.c	8.1 (Berkeley) 5/31/93";
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"trek.h"
end_include

begin_comment
comment|/* **	global variable definitions */
end_comment

begin_decl_stmt
name|struct
name|device
name|Device
index|[
name|NDEV
index|]
init|=
block|{
literal|"warp drive"
block|,
literal|"Scotty"
block|,
literal|"S.R. scanners"
block|,
literal|"Scotty"
block|,
literal|"L.R. scanners"
block|,
literal|"Scotty"
block|,
literal|"phasers"
block|,
literal|"Sulu"
block|,
literal|"photon tubes"
block|,
literal|"Sulu"
block|,
literal|"impulse engines"
block|,
literal|"Scotty"
block|,
literal|"shield control"
block|,
literal|"Sulu"
block|,
literal|"computer"
block|,
literal|"Spock"
block|,
literal|"subspace radio"
block|,
literal|"Uhura"
block|,
literal|"life support"
block|,
literal|"Scotty"
block|,
literal|"navigation system"
block|,
literal|"Chekov"
block|,
literal|"cloaking device"
block|,
literal|"Scotty"
block|,
literal|"transporter"
block|,
literal|"Scotty"
block|,
literal|"shuttlecraft"
block|,
literal|"Scotty"
block|,
literal|"*ERR 14*"
block|,
literal|"Nobody"
block|,
literal|"*ERR 15*"
block|,
literal|"Nobody"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Systemname
index|[
name|NINHAB
index|]
init|=
block|{
literal|"ERROR"
block|,
literal|"Talos IV"
block|,
literal|"Rigel III"
block|,
literal|"Deneb VII"
block|,
literal|"Canopus V"
block|,
literal|"Icarus I"
block|,
literal|"Prometheus II"
block|,
literal|"Omega VII"
block|,
literal|"Elysium I"
block|,
literal|"Scalos IV"
block|,
literal|"Procyon IV"
block|,
literal|"Arachnid I"
block|,
literal|"Argo VIII"
block|,
literal|"Triad III"
block|,
literal|"Echo IV"
block|,
literal|"Nimrod III"
block|,
literal|"Nemisis IV"
block|,
literal|"Centarurus I"
block|,
literal|"Kronos III"
block|,
literal|"Spectros V"
block|,
literal|"Beta III"
block|,
literal|"Gamma Tranguli VI"
block|,
literal|"Pyris III"
block|,
literal|"Triachus"
block|,
literal|"Marcus XII"
block|,
literal|"Kaland"
block|,
literal|"Ardana"
block|,
literal|"Stratos"
block|,
literal|"Eden"
block|,
literal|"Arrikis"
block|,
literal|"Epsilon Eridani IV"
block|,
literal|"Exo III"
block|}
decl_stmt|;
end_decl_stmt

end_unit

