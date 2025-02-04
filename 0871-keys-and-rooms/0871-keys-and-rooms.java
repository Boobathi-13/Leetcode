class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        boolean[] visitedRooms = new boolean[rooms.size()];

        // initially we will be visiting the first room.
        visitedRooms[0] = true;

        // explore all the rooms starting the first room.
        dfs(rooms, 0, visitedRooms);

        for(boolean visitedRoom: visitedRooms) {
            // if we have not visited a room return false
            if(!visitedRoom) return false;
        }

        // if we reach here; meaning we have visited all the rooms.
        return true;
    }

    void dfs(List<List<Integer>> rooms, int room, boolean[] visitedRooms) {

        // vist the room and pick up the keys from that room
        for(int roomKey: rooms.get(room)) {
            // visit the room only once with the room key
            if(visitedRooms[roomKey]) continue;

            // mark the room with the room key as true so we don't process the same room again and don't stuck forever.
            visitedRooms[roomKey] = true;

            // do a dfs with the neigboring room with the room key
            dfs(rooms, roomKey, visitedRooms);
        }
    }
}