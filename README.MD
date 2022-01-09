## Programming Language Design Assignment 10

### Environment

> ubuntu 20.04
> linux-5.14.15
> docker 20.10.7

### How to run it

```bash
# in host
docker build -t pld .
docker run --rm -it --name pld_a10 pld
# in docker
./main
```

### How to use my linked list
- `List<T>` is a struct to declare my linked list, T is template to any type
- You can use any type including `int`, `float`, `char`, `string`
- `add_element(List<T>, T val)` add element to the last of linked list
- `print_linked_list(List<T>)` print the linked list
- `reverse_linked_list(List<T>)` print the linked list first, then reverse the linked list and print the linked list after reversing
