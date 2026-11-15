<template>
  <view class="series-list">
    <view v-for="(group, gidx) in groups" :key="gidx" class="series-group">
      <view v-for="(item, idx) in group.items" :key="idx" class="series-item" @click="goDetail(item)">
        <image class="series-img" :src="item.img" mode="aspectFit" />
        <view class="series-info">
          <text class="series-name">{{ item.name }}</text>
        </view>
        <text class="series-arrow">&#62;</text>
      </view>
    </view>
  </view>
</template>

<script>
export default {
  name: 'SwitchSeries',
  data() {
    return {
      groups: [
        {
          desc: '',
          items: [
            { img: '../../../static/K-A.png', name: 'K-A', link: '/pages/series/switchDetail' },
            { img: '../../../static/K-C.jpg', name: 'K-C', link: '/pages/series/switchDetail2' }
          ]
        }
      ]
    }
  },
  methods: {
    goDetail(item) {
      if (item.link) {
        uni.navigateTo({ url: item.link });
      }
    }
  }
}
</script>

<style scoped>
.series-list {
  width: 100%;
  background: #fff;
  border-radius: 24rpx;
  padding: 0 0 24rpx 0;
}
.series-group {
  margin-bottom: 0;
}
.series-item {
  display: flex;
  align-items: center;
  padding: 18rpx 0 18rpx 24rpx;
  border-bottom: 1px solid #f0f0f0;
  background: #fff;
  min-height: 120rpx;
}
.series-item:last-child {
  border-bottom: none;
}
.series-item:active {
  background: #f5f5f5;
}
.series-img {
  width: 92rpx;
  height: 92rpx;
  border-radius: 12rpx;
  background: #f7f7f7;
  margin-right: 24rpx;
  flex-shrink: 0;
}
.series-info {
  flex: 1;
  display: flex;
  align-items: center;
  min-width: 0;
  justify-content: center;
}
.series-name {
  font-size: 30rpx;
  color: #222;
  font-weight: 500;
  white-space: nowrap;
  overflow: hidden;
  text-overflow: ellipsis;
}
.series-arrow {
  font-size: 36rpx;
  color: #bbb;
  margin-left: 16rpx;
  margin-right: 24rpx;
}
</style> 