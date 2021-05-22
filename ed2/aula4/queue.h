#ifndef QUEUE_H
#define QUEUE_H

#define queue_base       \
    struct {             \
        size_t cap, len, start; \
    }

#define queue(T)         \
    struct queue_##T{    \
        queue_base;      \
        T data[];        \
    }

#define queue_init(T)                                                         \
({                                                                            \
    const size_t initial_size = 16;                                           \
    struct queue_##T *q = malloc(sizeof(queue(T)) + sizeof(T) * initial_size);\
    q->cap = initial_size;                                                    \
    q->len = 0;                                                               \
    q->start = 0;                                                             \
    q;                                                                        \
})

#define queue_free(q) free(q)

#define queue_pop(q)({\
    q->data[q->start++];\
})

#define queue_ref(q, i) (&q->data[i + q->start])

#define queue_at(q, i) (*(queue_ref(q, i)))

#define queue_push(q, i)                                                \
({                                                                      \
    if (q->len >= q->cap) {                                             \
        q->cap *= 2;                                                    \
        q = realloc(q, sizeof(queue_base) + q->cap * sizeof(*q->data)); \
    }                                                                   \
    q->data[q->len++] = (i);                                 \
})

#define queue_size(q) (q->len - q->start)

#endif