def smap(x, inMin, inMax, outMin, outMax):
	return (x - inMin) * (outMax - outMin) / (inMax - inMin) + outMin

def parseObj(filePath):
    vertexCoords = []

    with open(filePath, 'r') as f:
        lines = f.readlines()

    for line in lines:
        split = line.split()
        if split and split[0] == "v":
            try:
                coords = list(map(float, split[1:]))
                if len(coords) == 3:
                    vertexCoords.append(coords)
            except ValueError:
                print(f"Ignored line: {line.strip()} (non-numeric coordinates)")

    return vertexCoords

objPath = input("Enter OBJ Path:")
vertices = parseObj(objPath)

for i in range(len(vertices)):
     vertices[i][0] = int(smap(vertices[i][0], -16, 16, 25, 50))
     vertices[i][1] = int(smap(vertices[i][1], -16, 16, 25, 50))
     vertices[i][2] = int(smap(vertices[i][2], -16, 16, 25, 50))

print(vertices)
