begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_TESTS_H
end_ifndef

begin_define
define|#
directive|define
name|_TESTS_H
end_define

begin_comment
comment|/*  * libfdt - Flat Device Tree manipulation  *	Testcase definitions  * Copyright (C) 2006 David Gibson, IBM Corporation.  *  * This library is free software; you can redistribute it and/or  * modify it under the terms of the GNU Lesser General Public License  * as published by the Free Software Foundation; either version 2.1 of  * the License, or (at your option) any later version.  *  * This library is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * Lesser General Public License for more details.  *  * You should have received a copy of the GNU Lesser General Public  * License along with this library; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA  */
end_comment

begin_define
define|#
directive|define
name|DEBUG
end_define

begin_comment
comment|/* Test return codes */
end_comment

begin_define
define|#
directive|define
name|RC_PASS
value|0
end_define

begin_define
define|#
directive|define
name|RC_CONFIG
value|1
end_define

begin_define
define|#
directive|define
name|RC_FAIL
value|2
end_define

begin_define
define|#
directive|define
name|RC_BUG
value|99
end_define

begin_decl_stmt
specifier|extern
name|int
name|verbose_test
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|test_name
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|test_init
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ALIGN
parameter_list|(
name|x
parameter_list|,
name|a
parameter_list|)
value|(((x) + (a) - 1)& ~((a) - 1))
end_define

begin_define
define|#
directive|define
name|PALIGN
parameter_list|(
name|p
parameter_list|,
name|a
parameter_list|)
value|((void *)ALIGN((unsigned long)(p), (a)))
end_define

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|x
parameter_list|)
value|(sizeof(x) / sizeof((x)[0]))
end_define

begin_define
define|#
directive|define
name|streq
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp((s1),(s2)) == 0)
end_define

begin_comment
comment|/* Each test case must define this function */
end_comment

begin_function_decl
name|void
name|cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|verbose_printf
parameter_list|(
modifier|...
parameter_list|)
define|\
value|if (verbose_test) { \ 		printf(__VA_ARGS__); \ 		fflush(stdout); \ 	}
end_define

begin_define
define|#
directive|define
name|ERR
value|"ERR: "
end_define

begin_define
define|#
directive|define
name|ERROR
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|fprintf(stderr, ERR fmt, ## args)
end_define

begin_define
define|#
directive|define
name|PASS
parameter_list|()
define|\
value|do {						\ 		cleanup();				\ 		printf("PASS\n");			\ 		exit(RC_PASS);				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|PASS_INCONCLUSIVE
parameter_list|()
define|\
value|do {						\ 		cleanup();				\ 		printf("PASS (inconclusive)\n");	\ 		exit(RC_PASS);				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|IRRELEVANT
parameter_list|()
define|\
value|do {						\ 		cleanup();				\ 		printf("PASS (irrelevant)\n");		\ 		exit(RC_PASS);				\ 	} while (0)
end_define

begin_comment
comment|/* Look out, gcc extension below... */
end_comment

begin_define
define|#
directive|define
name|FAIL
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {						\ 		cleanup();				\ 		printf("FAIL\t" fmt "\n", ##__VA_ARGS__);	\ 		exit(RC_FAIL);				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|CONFIG
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {						\ 		cleanup();				\ 		printf("Bad configuration: " fmt "\n", ##__VA_ARGS__);	\ 		exit(RC_CONFIG);			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TEST_BUG
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {						\ 		cleanup();				\ 		printf("BUG in testsuite: " fmt "\n", ##__VA_ARGS__);	\ 		exit(RC_BUG);				\ 	} while (0)
end_define

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|xmalloc
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
name|void
modifier|*
name|p
init|=
name|malloc
argument_list|(
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|p
condition|)
name|FAIL
argument_list|(
literal|"malloc() failure"
argument_list|)
expr_stmt|;
return|return
name|p
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|xrealloc
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|p
operator|=
name|realloc
argument_list|(
name|p
argument_list|,
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|p
condition|)
name|FAIL
argument_list|(
literal|"realloc() failure"
argument_list|)
expr_stmt|;
return|return
name|p
return|;
block|}
end_function

begin_function_decl
name|void
name|check_mem_rsv
parameter_list|(
name|void
modifier|*
name|fdt
parameter_list|,
name|int
name|n
parameter_list|,
name|uint64_t
name|addr
parameter_list|,
name|uint64_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|check_property
parameter_list|(
name|void
modifier|*
name|fdt
parameter_list|,
name|int
name|nodeoffset
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|len
parameter_list|,
specifier|const
name|void
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|check_property_cell
parameter_list|(
name|fdt
parameter_list|,
name|nodeoffset
parameter_list|,
name|name
parameter_list|,
name|val
parameter_list|)
define|\
value|({ \ 		uint32_t x = cpu_to_fdt32(val);			      \ 		check_property(fdt, nodeoffset, name, sizeof(x),&x); \ 	})
end_define

begin_function_decl
specifier|const
name|void
modifier|*
name|check_getprop
parameter_list|(
name|void
modifier|*
name|fdt
parameter_list|,
name|int
name|nodeoffset
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|len
parameter_list|,
specifier|const
name|void
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|check_getprop_cell
parameter_list|(
name|fdt
parameter_list|,
name|nodeoffset
parameter_list|,
name|name
parameter_list|,
name|val
parameter_list|)
define|\
value|({ \ 		uint32_t x = cpu_to_fdt32(val);			     \ 		check_getprop(fdt, nodeoffset, name, sizeof(x),&x); \ 	})
end_define

begin_define
define|#
directive|define
name|check_getprop_string
parameter_list|(
name|fdt
parameter_list|,
name|nodeoffset
parameter_list|,
name|name
parameter_list|,
name|s
parameter_list|)
define|\
value|check_getprop((fdt), (nodeoffset), (name), strlen(s)+1, (s))
end_define

begin_function_decl
name|int
name|nodename_eq
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|load_blob
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|load_blob_arg
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|save_blob
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|void
modifier|*
name|blob
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|open_blob_rw
parameter_list|(
name|void
modifier|*
name|blob
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TESTS_H */
end_comment

end_unit

