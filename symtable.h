/*
 * Copyright (c) 2016, Continuum Analytics, Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * Redistributions of source code must retain the above copyright notice,
 *
 * this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef SYMTABLE_H
#define SYMTABLE_H


/*****************************************************************************/
/*                     Symbol tables used in type matching                   */
/*****************************************************************************/

enum symtable_entry {
  Unbound,
  SizeEntry,
  SymbolEntry,
  TypeEntry
};

typedef struct {
  enum symtable_entry tag;
  union {
    size_t SizeEntry;
    const char *SymbolEntry;
    const ndt_t *TypeEntry;
  };
} symtable_entry_t;

typedef struct symtable {
    symtable_entry_t entry;
    struct symtable *next[];
} symtable_t;

symtable_t *symtable_new(ndt_context_t *ctx);
void symtable_del(symtable_t *t);
int symtable_add(symtable_t *t, const char *key, const symtable_entry_t entry,
                 ndt_context_t *ctx);
symtable_entry_t symtable_find(const symtable_t *t, const char *key);


#endif /* SYMTABLE_H */
