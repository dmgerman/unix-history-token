begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1995 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby  * granted, provided that both the above copyright notice and this  * permission notice appear in all copies, that both the above  * copyright notice and this permission notice appear in all  * supporting documentation, and that the name of M.I.T. not be used  * in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission.  M.I.T. makes  * no representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied  * warranty.  *  * THIS SOFTWARE IS PROVIDED BY M.I.T. ``AS IS''.  M.I.T. DISCLAIMS  * ALL EXPRESS OR IMPLIED WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT  * SHALL M.I.T. BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|country
block|{
specifier|const
name|char
modifier|*
modifier|*
name|c_filelist
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
name|c_menu
decl_stmt|;
name|int
name|c_count
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|region
block|{
name|struct
name|country
modifier|*
modifier|*
name|r_ctrylist
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
name|r_menu
decl_stmt|;
name|int
name|r_count
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|region
name|Africa
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* all of Africa */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|region
name|America
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* North and South America */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|region
name|Asia
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* all of Asia */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|region
name|Atlantic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Atlantic Ocean islands */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|region
name|Australia
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Australia */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|region
name|Europe
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* all of Europe including Russia */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|region
name|Indian
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indian Ocean islands */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|region
name|Pacific
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pacific Ocean islands */
end_comment

begin_function_decl
specifier|extern
name|int
name|setzone
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|tzmenu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

