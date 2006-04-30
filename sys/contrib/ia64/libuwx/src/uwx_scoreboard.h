begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2003 Hewlett-Packard Development Company, L.P. Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
end_comment

begin_define
define|#
directive|define
name|NSB_SPECIAL
value|9
end_define

begin_define
define|#
directive|define
name|NSB_GR
value|4
end_define

begin_define
define|#
directive|define
name|NSB_BR
value|5
end_define

begin_define
define|#
directive|define
name|NSB_FR
value|20
end_define

begin_define
define|#
directive|define
name|SBREG_RP
value|0
end_define

begin_define
define|#
directive|define
name|SBREG_PSP
value|1
end_define

begin_define
define|#
directive|define
name|SBREG_PFS
value|2
end_define

begin_define
define|#
directive|define
name|SBREG_PREDS
value|3
end_define

begin_define
define|#
directive|define
name|SBREG_UNAT
value|4
end_define

begin_define
define|#
directive|define
name|SBREG_PRIUNAT
value|5
end_define

begin_define
define|#
directive|define
name|SBREG_RNAT
value|6
end_define

begin_define
define|#
directive|define
name|SBREG_LC
value|7
end_define

begin_define
define|#
directive|define
name|SBREG_FPSR
value|8
end_define

begin_define
define|#
directive|define
name|SBREG_GR
value|(0 + NSB_SPECIAL)
end_define

begin_define
define|#
directive|define
name|SBREG_BR
value|(SBREG_GR + NSB_GR)
end_define

begin_define
define|#
directive|define
name|SBREG_FR
value|(SBREG_BR + NSB_BR)
end_define

begin_define
define|#
directive|define
name|NSBREG_NOFR
value|(NSB_SPECIAL + NSB_GR + NSB_BR)
end_define

begin_define
define|#
directive|define
name|NSBREG
value|(NSB_SPECIAL + NSB_GR + NSB_BR + NSB_FR)
end_define

begin_struct
struct|struct
name|uwx_scoreboard
block|{
name|struct
name|uwx_scoreboard
modifier|*
name|nextused
decl_stmt|;
name|struct
name|uwx_scoreboard
modifier|*
name|nextfree
decl_stmt|;
name|struct
name|uwx_scoreboard
modifier|*
name|nextstack
decl_stmt|;
name|struct
name|uwx_scoreboard
modifier|*
name|nextlabel
decl_stmt|;
name|uint64_t
name|rstate
index|[
name|NSBREG
index|]
decl_stmt|;
name|int
name|label
decl_stmt|;
name|int
name|id
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|struct
name|uwx_scoreboard
modifier|*
name|uwx_alloc_scoreboard
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|uwx_scoreboard
modifier|*
name|uwx_init_scoreboards
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|uwx_scoreboard
modifier|*
name|uwx_new_scoreboard
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
name|struct
name|uwx_scoreboard
modifier|*
name|prevsb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|uwx_scoreboard
modifier|*
name|uwx_pop_scoreboards
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
name|struct
name|uwx_scoreboard
modifier|*
name|sb
parameter_list|,
name|int
name|ecount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uwx_label_scoreboard
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
name|struct
name|uwx_scoreboard
modifier|*
name|sb
parameter_list|,
name|int
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uwx_copy_scoreboard
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
name|struct
name|uwx_scoreboard
modifier|*
name|sb
parameter_list|,
name|int
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|uwx_free_scoreboards
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

end_unit

