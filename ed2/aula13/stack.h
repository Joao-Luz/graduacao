#ifndef STACK_H
#define STACK_H

#define stack_base       \
    struct {             \
        size_t cap, len; \
    }

#define stack(T)         \
    struct stack_##T{    \
        stack_base;      \
        T data[];        \
    }

#define stack_init(T)                                                         \
({                                                                            \
    const size_t initial_size = 16;                                           \
    struct stack_##T *s = malloc(sizeof(stack(T)) + sizeof(T) * initial_size);\
    s->cap = initial_size;                                                    \
    s->len = 0;                                                               \
    s;                                                                        \
})

#define stack_free(s) free(s)

#define stack_pop(s) (s->data[--s->len])

#define stack_ref(s, i) (&s->data[i])

#define stack_at(s, i) (*(stack_ref(s, i)))

#define stack_push(s, i)                                                \
({                                                                      \
    if (s->len >= s->cap) {                                             \
        s->cap *= 2;                                                    \
        s = realloc(s, sizeof(stack_base) + s->cap * sizeof(*s->data)); \
    }                                                                   \
    s->data[s->len++] = (i);                                            \
})

#define stack_size(s) (s->len)

#endif