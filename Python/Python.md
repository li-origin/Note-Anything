# Python
________

## **类：**
---
> ***在 Python 中，类的属性可以分为两种：类属性和实例属性。*** 

类属性是指定义在类中，但在方法之外的属性。类属性是类的所有实例共享的，可以通过类名或实例访问，不需要使用 `self` 关键字。实例属性是指定义在方法中，且以 `self` 作为前缀的属性。实例属性是每个实例独有的，只能通过实例访问，需要使用 `self` 关键字。下面是一个示例代码，展示了类属性和实例属性的使用：

```python
class MyClass:
    class_attr = "I am a class attribute"

    def __init__(self, instance_attr):
        self.instance_attr = instance_attr

obj1 = MyClass("I am an instance attribute of obj1")
obj2 = MyClass("I am an instance attribute of obj2")

print(MyClass.class_attr)  # Output: I am a class attribute
print(obj1.class_attr)     # Output: I am a class attribute
print(obj2.class_attr)     # Output: I am a class attribute

print(obj1.instance_attr)  # Output: I am an instance attribute of obj1
print(obj2.instance_attr)  # Output: I am an instance attribute of obj2
```

> 在上面的代码中，`class_attr` 是一个类属性，而 `instance_attr` 是一个实例属性。注意到在 `__init__` 方法中，我们使用了 `self.instance_attr` 来定义实例属性。