# RayTracing

## Practicing with Ray Tracing Technology Using C++

This project has helped me better understand how to use C++ in terms of creating actual software. I recommend anyone who wants to learn C++ and how ray tracing technology works to follow the guides below. I want to personally thank Steve Hollasch as he has helped answer some of my questions on this topic.

[Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html) 


## Why is There Different Folders and/or Files with the Same Name but Different Version Numbers?

When working on this project I typically found that new code was being built on top of old code and that the old code itself was being improved for efficiency. I wanted to record each iteration where there was a drastic step in the code. Since drastic is rather subjective, I went with my own intuition on what constitued a new "version". I found that this way of recording what I had done has allowed me to go back, look at old code and understand the intution behind the new code and new concepts being presented in each of the books. The top folders, RayTracingV1, RayTracingV2, and RayTracingV3 represent the 3 different books on topic.

## Images

<img width="600" alt="Image1" src="https://user-images.githubusercontent.com/78282234/139567760-b41cb32d-3455-42af-9f1b-15be6d9d0b67.png">

Three matte spheres diffused using true Lambertian reflections

<img width="600" alt="Screen Shot 2021-11-06 at 1 08 19 PM" src="https://user-images.githubusercontent.com/78282234/140619563-42c34d70-e11c-491c-930c-8b3406c3d512.png">

2 metal spheres displaying "fuzzy reflections" using random points in a unit sphere similar to how lambertian reflections reflect light to random points on the surface of a unit sphere (the unit sphere in both cases is tangent to the point where the ray hits the surface). The left has a much lower "fuzz" factor (0 to be exact) than the right sphere. The middle sphere is a matte sphere. At this point in the ray tracer we are able to give colors to the spheres as well as materials with certain properties to the spheres themselves.
